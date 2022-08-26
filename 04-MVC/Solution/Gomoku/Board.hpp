#pragma once
#include <vector>

enum class CELL_TYPE { NONE, KRESTIK, NOLIK };

enum class WIN_TYPE { NONE, KRESTIK, NOLIK, DRAW };

class Board
{
	const size_t size;
	std::vector<std::vector<CELL_TYPE>> field;
	WIN_TYPE game_status;

public:

	Board(int _size = 3) : size(_size)
	{
		field.resize(size);
		for (int i = 0; i < size; ++i)
		{
			field[i].resize(size, CELL_TYPE::NONE);
		}
		game_status = WIN_TYPE::NONE;
	}

	size_t get_size() const { return size; }

	CELL_TYPE get_cell(size_t i, size_t j) const
	{
		return field[i][j];
	}

	bool set_cell(size_t i, size_t j, CELL_TYPE cell_value)
	{
		if (i < size && j < size && field[i][j] == CELL_TYPE::NONE)
		{
			field[i][j] = cell_value;
			return true;
		}
		else
			return false;
	}

	WIN_TYPE get_status_game()
	{
		// ???
		return WIN_TYPE::NONE;
	}
};