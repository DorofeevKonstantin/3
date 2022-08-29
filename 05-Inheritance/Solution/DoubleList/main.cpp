#include <iostream>

using namespace std;

class List
{
protected:
	int value;
	List* next;
public:
	List(int value_)
	{
		value = value_;
		next = 0;
	}
	virtual void addValue(int value_)
	{
		List* current = this;
		while (current->next != 0)
		{
			current = current->next;
		}
		current->next = new List(value_);
	}
	void output()
	{
		List* current = this;
		while (current != 0)
		{
			if (current->next != 0) cout << current->value << " -> ";
			else cout << current->value;
			current = current->next;
		}
		cout << endl;
	}
};

class DoubleList : public List
{
private:
	DoubleList* prev;
	DoubleList* tail;
public:
	DoubleList(int value_) : List(value_), tail(0), prev(0)
	{

	}
	void addValue(int value_) override
	{
		DoubleList* current = this;
		while (current->next != 0)
		{
			current = static_cast<DoubleList*>(current->next);
		}
		current->next = new DoubleList(value_);
		(static_cast<DoubleList*>(current->next))->prev = current;
		tail = static_cast<DoubleList*>(current->next);
	}
	void reverseOutput()
	{
		DoubleList* current = tail;
		while (current != 0)
		{
			if (current->prev != 0) cout << current->value << " -> ";
			else cout << current->value;
			current = current->prev;
		}
		cout << endl;
	}
};
void addSequence(List* l, int value_, size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		l->addValue(value_);
	}
}

int main()
{
	List l(0);
	DoubleList l2(0);
	addSequence(&l, 9, 10);
	addSequence(&l2, 9, 10);
	l.output();
	l2.output();
	cout << "l2.reverseOutput()" << endl;
	l2.reverseOutput();
	return 0;
}