#include <iostream>
#include <concepts>
#include <string>
#include <algorithm>

class string_ext : public std::string
{
public:
	string_ext(const char* symbols) : std::string(symbols) {}

	string_ext(const string_ext& obj) : std::string(obj.c_str()) {}

	void operator=(const std::string& obj)
	{
		this->clear();
		this->append(obj.c_str());
	}

	void operator=(const char* symbols)
	{
		this->clear();
		this->append(symbols);
	}

	string_ext operator%(const string_ext& obj)
	{
		string_ext result = "";
		if (strcmp(this->data(), obj.data()) == 0)
			return result;
		int total_same_values = 0;
		for (unsigned int i = 0; i < this->size(); ++i)
		{
			int same_values = 0, same_started_index = -1;
			unsigned int j = 0;
			for (; j < obj.size(); ++j)
			{
				if ((i + j) >= this->size())
					break;
				if (this->data()[i + j] == obj[j])
				{
					++same_values;
					if (same_started_index == -1)
						same_started_index = j;
				}
			}
			if (same_values > total_same_values)
			{
				total_same_values = same_values;
				result = std::string(obj.begin() + same_started_index, obj.begin() + same_started_index + same_values);
			}
		}
		return result;
	}

	operator bool()
	{
		return !this->empty();
	}

	int operator<(const string_ext& obj)
	{
		return this->size() < obj.size();
	}

	bool operator==(const string_ext& obj)
	{
		return strcmp(this->c_str(), obj.c_str()) == 0;
	}
};

template<class T>
concept Boolable = requires(T obj)
{
	{ obj }  -> std::convertible_to<bool>;
};

template<class T>
concept Divisible = requires(T dividend, T divisor)
{
	dividend% divisor;
};

template<class T>
concept Lessable = requires(T lhs, T rhs)
{
	lhs < rhs;
};

template<class T>
concept Swappable = requires(T lhs, T rhs)
{
	std::swap<T>(lhs, rhs);
};

template <class T>
T gcd(T a, T b) requires Boolable<T>&& Divisible<T>&& Lessable<T>&& Swappable<T>
{
	if (a < b)
		std::swap(a, b);
	return b ? gcd<T>(b, a % b) : a;
}

template <class T>
void output_gcd(T& left, T& right)
{
	std::cout << "gcd(" << left << "," << right << ") == " << gcd<T>(left, right) << std::endl;
}

void gcd_examples();