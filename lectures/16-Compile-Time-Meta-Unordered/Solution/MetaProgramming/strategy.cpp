#include "strategy.hpp"

void strategyClientCode()
{
	Context* context = new Context(new ConcreteStrategyA);
	std::cout << "Client: Strategy is set to normal sorting." << std::endl;
	context->businessTask();
	std::cout << "Client: Strategy is set to reverse sorting." << std::endl;
	context->setStrategy(new ConcreteStrategyB);
	context->businessTask();
	delete context;
}