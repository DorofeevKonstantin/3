#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <filesystem>
#include <iomanip>

class Logger
{
public:
	static std::string currentDate()
	{
		auto now = std::chrono::system_clock::now();
		auto in_time_t = std::chrono::system_clock::to_time_t(now);
		tm _tm;
		localtime_s(&_tm, &in_time_t);
		std::stringstream ss;
		ss << std::put_time(&_tm, "%Y-%m-%d");
		std::string result = ss.str();
		return result;
	}
	static void Init()
	{
		try
		{
			std::string directory = "Logs";
			std::filesystem::create_directory(directory);
			std::string fileName = directory + "\\" + currentDate() + ".txt";
			logger = new Logger(fileName);
			Log("Program started, " + fileName + " created");
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (...)
		{
			std::cerr << "Unknown exception in Logger::Init." << std::endl;
		}
	}
	static void Log(std::string message)
	{
		try
		{
			if (logger)
				logger->loggerFile << currentDateAndTime() << message << std::endl;
			std::cout << message << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (...)
		{
			std::cerr << "unknown exception" << std::endl;
		}
	}
private:
	std::ofstream loggerFile;
	static Logger* logger;
	static std::string currentDateAndTime()
	{
		auto now = std::chrono::system_clock::now();
		auto in_time_t = std::chrono::system_clock::to_time_t(now);
		tm _tm;
		localtime_s(&_tm, &in_time_t);
		std::stringstream ss;
		ss << std::put_time(&_tm, "%Y-%m-%d %X : ");
		return ss.str();
	}
	Logger(std::string path)
	{
		try
		{
			loggerFile.open(path, std::ios_base::app | std::ios_base::out);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (...)
		{
			std::cerr << "unknown exception" << std::endl;
		}
	}
};