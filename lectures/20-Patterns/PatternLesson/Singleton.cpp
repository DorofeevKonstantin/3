class Context
{
public:
	void doUsefullStuff() {};
};

class Singleton
{
public:
	Singleton() = delete;
	Singleton(const Singleton&) = delete;

	static Context* getContext() 
	{
		if (c == nullptr)
			c = new Context;
		return c;
	}

private:
	static Context* c;
};

Context* Singleton::c = nullptr;


class Object1
{
public:
	void foo()
	{
		Context* tmpc = Singleton::getContext();
		tmpc->doUsefullStuff();
		//...
	}
};

int f()
{
	Object1 obj;
	obj.foo();
	return 0;
}