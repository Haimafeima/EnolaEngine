#include "JobSystem.h"
void Initialize()
{
    // Initialize the worker execution state to 0:
    finishedLabel.store(0);

    // Retrieve the number of hardware threads in this system:
    auto numCores = std::thread::hardware_concurrency();

    // Calculate the actual number of worker threads we want:
    numThreads = std::max(1u, numCores);

    // Create all our worker threads while immediately starting them:
    for (uint32_t threadID = 0; threadID < numThreads; ++threadID)
    {
        std::thread worker([] {

            std::function<void()> job; // the current job for the thread, it's empty at start.

            // This is the infinite loop that a worker thread will do 
            while (true)
            {
                if (jobPool.pop_front(job)) // try to grab a job from the jobPool queue
                {
                    // It found a job, execute it:
                    job(); // execute job
                    finishedLabel.fetch_add(1); // update worker label state
                }
                else
                {
                    // no job, put thread to sleep
                    std::unique_lock<std::mutex> lock(wakeMutex);
                    wakeCondition.wait(lock);
                }
            }

            });

        // *****Here we could do platform specific thread setup...

        worker.detach(); // forget about this thread, let it do it's job in the infinite loop that we created above
    }
}