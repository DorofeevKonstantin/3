#pragma once

#include <exception>

class NetWorkConnection
{
public:
	void connect() {}
	~NetWorkConnection()
	{
		// work with File I/O in STL style, can be exceptions
		try
		{

		}
		catch (const std::exception& e)
		{
			// handle errors
		}
	}
};

//void foo()
//{
//	NetWorkConnection nc;
//	nc.connect();
//}