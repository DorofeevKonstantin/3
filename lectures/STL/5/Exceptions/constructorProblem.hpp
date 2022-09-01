#pragma once

#include <string>

template <class image_t>
class BookEntry {
private:
	std::string name;
	image_t* image;
public:
	BookEntry(const std::string& name_, const std::string& filename)
	{
		try
		{
			name = name_;
			// problem with exception in image_t constructor
			image = new image_t(filename);
		}
		catch (const std::exception& e)
		{
			delete image;
		}
	}
	// destructor not called for unfinished objects
	~BookEntry()
	{
		delete image;
	}
};
