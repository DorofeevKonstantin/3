#include <string>
#include <vector>
#include <iostream>

#include "Logger.hpp"
#include "MultiThreadSingleton.hpp"

Logger* Logger::logger;
Singleton* Singleton::pinstance_{ nullptr };
std::mutex Singleton::mutex_;

void ThreadFoo()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton* singleton = Singleton::GetInstance("FOO");
	std::cout << singleton->value() << "\n";
}

void ThreadBar()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton* singleton = Singleton::GetInstance("BAR");
	std::cout << singleton->value() << "\n";
}

int main()
{
	Logger::Init();
	Logger::Log("test message");
	try
	{
		throw std::exception("some error");
	}
	catch (const std::exception& e)
	{
		Logger::Log(e.what());
	}

	std::cout << std::endl << "If you see the same value, then singleton was reused." << std::endl <<
		"If you see different values, then 2 singletons were created." << std::endl << std::endl;
	std::thread t1(ThreadFoo);
	std::thread t2(ThreadBar);
	t1.join();
	t2.join();
	return 0;
}