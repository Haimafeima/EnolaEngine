class SystemBase
{
public:
	SystemBase();
	virtual ~SystemBase();
	virtual bool Tick()=0;

private:

};

SystemBase::SystemBase()
{
}

SystemBase::~SystemBase()
{
}