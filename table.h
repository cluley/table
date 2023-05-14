#pragma once

template<class T>
class table {
public:
	table(const int& rows, const int& columns) : rows_(rows), columns_(columns) {
		grid = new T * [rows_];

		for (int i = 0; i < rows; ++i) {
			grid[i] = new T[columns_];
		}
	}

	table(const table&) = delete;

	~table() {
		for (int i = 0; i < rows_; ++i) {
			delete[] grid[i];
		}

		delete[] grid;
	}

	table& operator=(const table&) = delete;

	class proxy {
	public:
		proxy(int* row) : _row(row) {}
		proxy operator[](int idx) const { return _array[idx]; }
	private:
		T* _row;
	};

	proxy operator[](int idx) const {
		return proxy(grid[idx]);
	}
private:
	int rows_;
	int columns_;
	T** grid;
};