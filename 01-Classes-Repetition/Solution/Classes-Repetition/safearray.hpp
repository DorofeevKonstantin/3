#pragma once

#include <iostream>
#include <random>
#include <exception>
#include <cstring>

class safearray
{
private:
	size_t size;
	int* data;
public:
	safearray(size_t _size = 0) :size(_size), data(nullptr)
	{
		if (size > 0)
			data = new int[size];
	}
	safearray(const safearray& obj) noexcept
	{
		size = obj.size;
		data = new int[size];
		std::memcpy((void*)data, (void*)obj.data, size * sizeof(int));
	}
	safearray(safearray&& obj) noexcept
	{
		size = obj.size;
		data = new int[size];
		std::memcpy((void*)data, (void*)obj.data, size * sizeof(int));
		obj.data = nullptr;
		obj.size = 0;
	}
	safearray& operator=(safearray& obj) noexcept
	{
		delete[] data;
		size = obj.size;
		data = new int[size];
		std::memcpy((void*)data, (void*)obj.data, size * sizeof(int));
		return *this;
	}
	safearray& operator=(safearray&& obj) noexcept
	{
		delete[] data;
		size = obj.size;
		data = new int[size];
		std::memcpy((void*)data, (void*)obj.data, size * sizeof(int));
		obj.data = nullptr;
		obj.size = 0;
		return *this;
	}
	~safearray()
	{
		delete[] data;
	}
	void fillRandom()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		for (size_t i = 0; i < size; i++)
			data[i] = gen() % size;
	}
	int& operator[](size_t index)
	{
		if (index < size)
			return data[index];
		else
			throw std::range_error("bad index in safearray");
	}
	void print() const
	{
		std::cout << "safearray: ";
		for (size_t i = 0; i < size; i++)
			std::cout << data[i] << " ";
		std::cout << std::endl;
	}
	static void test();
};