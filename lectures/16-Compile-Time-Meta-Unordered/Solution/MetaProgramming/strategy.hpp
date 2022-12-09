#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Strategy is a behavioral design pattern that lets you define a family of algorithms,
// put each of them into a separate class, and make their objects interchangeable.

// ../../strategy.png 

// source : https://refactoring.guru/ru/design-patterns/strategy/cpp/example
class Strategy
{
public:
	virtual ~Strategy() {}
	virtual std::string algorithm(const std::vector<std::string>& data) const = 0;
};

class Context
{
private:
	Strategy* strategy;
public:
	Context(Strategy* strategy = nullptr) : strategy(strategy) {}
	~Context()
	{
		delete strategy;
	}
	void setStrategy(Strategy* _strategy)
	{
		delete this->strategy;
		this->strategy = _strategy;
	}
	void businessTask() const
	{
		std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)" << std::endl;
		std::string result = this->strategy->algorithm(std::vector<std::string>{"a", "e", "c", "b", "d"});
		std::cout << "result : " << result << std::endl;
	}
};

class ConcreteStrategyA : public Strategy
{
public:
	std::string algorithm(const std::vector<std::string>& data) const override
	{
		std::string result;
		std::for_each(std::begin(data), std::end(data), [&result](const std::string& word)
			{
				result += word;
			});
		std::sort(std::begin(result), std::end(result));
		return result;
	}
};
class ConcreteStrategyB : public Strategy
{
public:
	std::string algorithm(const std::vector<std::string>& data) const override
	{
		std::string result;
		std::for_each(std::begin(data), std::end(data), [&result](const std::string& word)
			{
				result += word;
			});
		std::sort(std::begin(result), std::end(result), [](const char& lhs, const char& rhs)
			{
				return lhs > rhs;
			});
		return result;
	}
};

void strategyClientCode();