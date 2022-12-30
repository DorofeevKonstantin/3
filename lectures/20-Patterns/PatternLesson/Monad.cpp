#include <iostream>
#include <vector>
using namespace std;

#define STACKTRACE

#ifdef STACKTRACE

size_t totalConstructorCalls = 0;
size_t totalDestructorCalls = 0;

#endif // STACKTRACE


template<typename T>
class Monad
{
private:
	T value;
public:

	Monad()
	{
#ifdef STACKTRACE
		cout << "Called default constructor by Monad()" << endl;
		totalConstructorCalls++;
#endif // STACKTRACE
	};
	Monad(const Monad& rhs)
	{
#ifdef STACKTRACE
		cout << "Called copy constructor by Monad(const Monad& rhs)" << endl;
		totalConstructorCalls++;
#endif // STACKTRACE
		this->value = rhs.value;
	}
	void operator=(const Monad& rhs)
	{
		this->value = rhs.value;


#ifdef STACKTRACE
		cout << "Called equal constructor by operator=(const Monad& rhs)" << endl;
		totalConstructorCalls++;
#endif // STACKTRACE

	}
	Monad(T _value)
	{
		value = _value;


#ifdef STACKTRACE
		cout << "Called value constructor by Monad(T rhs)" << endl;
		totalConstructorCalls++;
#endif // STACKTRACE
	}
	T& unwrap()
	{
		return value;
	}
	~Monad()
	{
#ifdef STACKTRACE
		cout << "Called destructor by ~Monad()" << endl;
		totalDestructorCalls++;
#endif // STACKTRACE
	}
};

template <typename T>
class Wrapper final
{
private:
	Monad<T> mvalue;

public:
	Wrapper(T rhs)
	{
		mvalue = Monad<T>(rhs);


#ifdef STACKTRACE
		cout << "Called value constructor by Wrapper(T rhs)" << endl;
		totalConstructorCalls++;
#endif // STACKTRACE
	}
	Wrapper(const Wrapper& rhs)
	{
		this->mvalue = Monad<T>(rhs.mvalue);




#ifdef STACKTRACE
		cout << "Called copy constructor by operator=(const Wrapper& rhs)" << endl;
		totalConstructorCalls++;
#endif // STACKTRACE
	}
	void operator=(const Wrapper& rhs)
	{
		this->mvalue = Monad<T>(rhs.mvalue);


#ifdef STACKTRACE
		cout << "Called equal constructor by operator=(const Wrapper& rhs)" << endl;
		totalConstructorCalls++;
#endif // STACKTRACE
	}
	Wrapper()
	{
#ifdef STACKTRACE
		cout << "Called constructor by Wrapper()" << endl;
		totalConstructorCalls++;
#endif // STACKTRACE
		//mvalue = nullptr;
	}

	template <typename G>
	Wrapper<G> transform(G tranformer(T& rhs))
	{
		Wrapper<G> tmpwrap = tranformer(this->unwrap());
		return tmpwrap;
	}

	T& unwrap()
	{
		return mvalue.unwrap();
	}

	~Wrapper()
	{
#ifdef STACKTRACE
		cout << "Called destructor by ~Wrapper()" << endl;
		totalDestructorCalls++;
#endif // STACKTRACE
	}
};

int MonadTest()
{
	Wrapper<int> myInt = '1';
	cout << "Wrapper<int> myInt: " << myInt.unwrap() << endl;

	Wrapper<int> myNewInt1 = myInt.transform<int>(
		[](int& rhs) -> int
		{
			return rhs * rhs;
		});
	cout << "Wrapper<int> myNewInt: " << myNewInt1.unwrap() << endl;





	Wrapper<string> myString1 = myInt.transform<string>(
		[](int& rhs) -> string
		{
			string tmp = "";
			tmp.append(5, rhs);
			return tmp;
		});

	cout << "Wrapper<string> myString1: " << myString1.unwrap() << endl;





	Wrapper<int> myNewInt2 = myString1.transform<int>(
		[](string& rhs) -> int
		{
			return atoi(rhs.c_str());
		});

	cout << "Wrapper<int> myNewInt: " << myNewInt2.unwrap() << endl;



	//Object.map().print();



	vector<int> v1 = { '1', '2', '3' };
	Wrapper<vector<int>> myVectorInt = v1;

	cout << "Wrapper<vector<int>> myVectorInt: ";
	for (size_t i = 0; i < myVectorInt.unwrap().size(); i++)
	{
		cout << myVectorInt.unwrap()[i] << " ";
	}
	cout << endl;







	Wrapper<string> myString2 = myVectorInt.transform<string>(
		[](vector<int>& rhs) -> string
		{
			string tmp = "";
			for (size_t i = 0; i < rhs.size(); i++)
			{
				tmp.append(1, rhs[i]);
			}
			return tmp;
		});
	cout << "Wrapper<string> myString2: " << myString2.unwrap() << endl;







	Wrapper<vector<double>> myVectorDouble = myVectorInt.transform<vector<double>>(
		[](vector<int>& rhs) -> vector<double>
		{
			vector<double> result;
			for (size_t i = 0; i < rhs.size(); i++)
			{
				result.push_back((double)rhs[i] + 0.351);
			}
			return result;
		});
	cout << "Wrapper<vector<double>> myVectorDouble: ";

	for (size_t i = 0; i < myVectorDouble.unwrap().size(); i++)
	{
		printf("%g ", myVectorDouble.unwrap()[i]);
	}
	cout << endl;






#ifdef STACKTRACE
	cout << "\n\nTotal construction calls = " << totalConstructorCalls << endl;
	cout << "Total destruction calls = " << totalDestructorCalls << endl;
#endif // STACKTRACE
	return 0;
}

