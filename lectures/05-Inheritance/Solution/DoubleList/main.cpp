#include <iostream>

using namespace std;

namespace KB
{
	class list
	{
	protected:
		int value;
		list* next;
	public:
		list(int value_)
		{
			value = value_;
			next = 0;
		}
		virtual void pushBack(int value_)
		{
			list* current = this;
			while (current->next != 0)
				current = current->next;
			current->next = new list(value_);
		}
		void print()
		{
			list* current = this;
			while (current != 0)
			{
				if (current->next != 0) cout << current->value << " -> ";
				else cout << current->value;
				current = current->next;
			}
			cout << endl;
		}
	};

	class doubleList : public list
	{
	private:
		doubleList* prev;
		doubleList* tail;
	public:
		doubleList(int value_) : list(value_), tail(0), prev(0)
		{

		}
		void pushBack(int value_) override
		{
			doubleList* current = this;
			while (current->next != 0)
				current = static_cast<doubleList*>(current->next);
			current->next = new doubleList(value_);
			(static_cast<doubleList*>(current->next))->prev = current;
			tail = static_cast<doubleList*>(current->next);
		}
		void reversePrint()
		{
			doubleList* current = tail;
			while (current != 0)
			{
				if (current->prev != 0) cout << current->value << " -> ";
				else cout << current->value;
				current = current->prev;
			}
			cout << endl;
		}
	};
	void addSequence(list* l, size_t count, int value)
	{
		for (size_t i = 0; i < count; ++i)
			l->pushBack(value);
	}
}

int main()
{
	KB::list l(0);
	l.pushBack(1);
	KB::doubleList l2(4);
	l2.pushBack(5);
	addSequence(&l, 3, 10);
	addSequence(&l2, 3, 10);
	l.print();
	l2.print();
	cout << "l2.reverseOutput()" << endl;
	l2.reversePrint();
	return 0;
}