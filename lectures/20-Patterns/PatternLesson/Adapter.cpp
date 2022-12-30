class SomeShitInterface
{
private:
	//...
public:
	void doUsefullStuff() {};
	//...
};


class AdapterComposition
{
	SomeShitInterface ssi;

public:
	void OurCoolFunction()
	{
		ssi.doUsefullStuff();
	}
	//...
};

class AdapterInheritance : SomeShitInterface
{
public:
	void OurCoolFunction()
	{
		doUsefullStuff();
	}
	//...
};

int AdapterExample()
{
	AdapterComposition AC;
	AdapterInheritance AI;
	AC.OurCoolFunction();
	return 0;
	// same as
	AI.OurCoolFunction();
}
