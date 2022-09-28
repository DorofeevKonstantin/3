#include <fstream>
#include <iostream>
#include <typeinfo>     // typeid()
#include <process.h>	// exit()
#include "Workers.h"
using namespace std;
int Employee::count_=0;
Employee** Employee::arrayPointers_=new Employee*[MAXEM];
void Employee::getData()
{
	cin.ignore(10, '\n');
	cout << "  Enter name: "; cin >> name_;
	cout << "  Enter number: ";    cin >> number_;
}
void Employee::putData()
{
	cout << "\n  Фамилия: " << name_;
	cout << "\n  Номер: " << number_;
}
Employee_type Employee::getType()
{
	if (typeid(*this) == typeid(Manager))
		return tmanager;
	else if (typeid(*this) == typeid(Scientist))
		return tscientist;
	else if (typeid(*this) == typeid(Laborer))
		return tlaborer;
	else
	{
		cerr << "\n UNKNOWN"; exit(1);
	}
	return tmanager;
}
void Employee::add()
{
	char choise;
	cout << "'m' for manager"
			"\n's' for scientist"
			"\n'l' for laborer"
			"\nYour choise: ";
	cin >> choise;
	switch (choise)
	{
	case 'm': arrayPointers_[count_] = new Manager;  break;
	case 's': arrayPointers_[count_] = new Scientist; break;
	case 'l': arrayPointers_[count_] = new Laborer;  break;
	default: cout << "\n UNKNOWN \n"; return;
	}
	arrayPointers_[count_++]->getData();
}
void Employee::display()
{
	for (int j = 0; j < count_; j++)
	{
		cout << (j + 1);
		switch (arrayPointers_[j]->getType())
		{
		case tmanager:  cout << ". Manager";  break;
		case tscientist: cout << ". Scientist"; break;
		case tlaborer:   cout << ". Laborer";  break;
		default: cout << ". UNKNOWN";
		}
		arrayPointers_[j]->putData();
		cout << endl;
	}
}
void Employee::read()
{
	int size;
	Employee_type inputType;
	ifstream inputFile;
	inputFile.open("EMPLOY.DAT", ios::binary);
	if (!inputFile)
	{
		cout << "\n can't open file \n"; 
		return;
	}
	count_ = 0;
	while (true)
	{
		inputFile.read((char*)&inputType, sizeof(inputType));
		if (inputFile.eof())
			break;
		if (!inputFile)
		{
			cout << "\n can't read type \n"; return;
		}
		switch (inputType)
		{
		case tmanager:
			arrayPointers_[count_] = new Manager;
			size = sizeof(Manager);
			break;
		case tscientist:
			arrayPointers_[count_] = new Scientist;
			size = sizeof(Scientist);
			break;
		case tlaborer:
			arrayPointers_[count_] = new Laborer;
			size = sizeof(Laborer);
			break;
		default: cout << "\n unknown type \n"; return;
		}
		inputFile.read((char*)arrayPointers_[count_], size);
		if (!inputFile)
		{
			cout << "\n can't read from file \n"; return;
		}
		count_++;
	}
	cout << "Reading " << count_ << " workers\n";
	inputFile.close();
}
void Employee::write()
{
	int size;
	cout << "Writing " << count_ << " workers.\n";
	ofstream outputFile;
	Employee_type inputType;
	outputFile.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!outputFile)
	{
		cout << "\n can't open file \n"; return;
	}
	for (int j = 0; j < count_; j++)
	{
		inputType = arrayPointers_[j]->getType();
		outputFile.write((char*)&inputType, sizeof(inputType));
		switch (inputType)
		{
		case tmanager:  size = sizeof(Manager); break;
		case tscientist: size = sizeof(Scientist); break;
		case tlaborer:  size = sizeof(Laborer); break;
		}
		outputFile.write( (char*)(arrayPointers_[j]), size );
		if (!outputFile)
		{
			cout << "\n can't write to file \n"; return;
		}
	}
	outputFile.close();
}
///////////////////////////////////////////////////////////
void Manager::getData()
{
	Employee::getData();
	cout << "  Enter title: ";	cin >> title_;
	cout << "  Enter payment: ";	cin >> payment_;
}
void Manager::putData()
{
	Employee::putData();
	cout << "\n  Title: " << title_;
	cout << "\n  Payment: " << payment_;
}
///////////////////////////////////////////////////////////
void Scientist::getData()
{
	Employee::getData();
	cout << "  Enter publications: "; cin >> nPublications_;
}
void Scientist::putData()
{
	Employee::putData();
	cout << "\n  Publications: " << nPublications_;
}
///////////////////////////////////////////////////////////