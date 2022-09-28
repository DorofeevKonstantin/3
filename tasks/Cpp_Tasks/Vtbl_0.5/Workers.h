#pragma once
#ifndef _WORKERS_H
#define _WORKERS_H
const int LEN=32;
const int MAXEM=100;
enum Employee_type { tmanager, tscientist, tlaborer };
///////////////////////////////////////////////////////////
class Employee
{
private:
	char name_[LEN];
	unsigned long number_;
	static int count_;
	static Employee** arrayPointers_;
public:
	virtual void getData();
	virtual void putData();
	virtual Employee_type getType();
	static void add();					// add worker
	static void display();
	static void read();					// from file
	static void write();				// to file
};
///////////////////////////////////////////////////////////
class Manager : public Employee
{
private:
	char title_[LEN];		// "president" for example
	double payment_;		// 250 for example
public:
	void getData();
	void putData();
};
///////////////////////////////////////////////////////////
class Scientist : public Employee
{
private:
	int nPublications_;
public:
	void getData();
	void putData();
};
///////////////////////////////////////////////////////////
class Laborer : public Employee
{
};
#endif