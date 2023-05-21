#pragma once

#include <iostream>

template<class T>
class table {
public:
	table(const int& rows, const int& columns) : rows_(rows), columns_(columns) {
		grid = new T * [rows_];

		for (int i = 0; i < rows; ++i) {
			grid[i] = new T[columns_]();
		}
	}

	~table() {
		for (int i = 0; i < rows_; ++i) {
			delete[] grid[i];
		}

		delete[] grid;
	}

	table& operator=(const table&) = delete;

	class proxy {
	public:
		proxy(int* row, const int columns) : array(row), columns_(columns) {}
		T& operator[](int idx)
		{ 
			if(idx >= columns_) throw std::out_of_range("segmentation fault (core dumped)");
			return array[idx];
		}
		T operator[](int idx) const
		{
			if (idx >= columns_) throw std::out_of_range("segmentation fault (core dumped)");
			return array[idx];
		}
	private:
		T* array;
		const int columns_;
	};

	class cproxy {
	public:
		cproxy(int* row, const int columns) : array(row), columns_(columns) {}
		T operator[](int idx) const
		{
			if (idx >= columns_) throw std::out_of_range("segmentation fault (core dumped)");
			return array[idx];
		}
	private:
		T* array;
		const int columns_;
	};

	proxy operator[](int idx)
	{
		if (idx >= rows_) throw std::out_of_range("segmentation fault (core dumped)");
		return proxy(grid[idx], columns_);
	}

	cproxy operator[](int idx) const
	{
		if (idx >= rows_) throw std::out_of_range("segmentation fault (core dumped)");
		return cproxy(grid[idx], columns_);
	}
private:
	int rows_;
	int columns_;
	T** grid;
};