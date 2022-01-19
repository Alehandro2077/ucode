#ifndef ARRAYHEADER_H
#define ARRAYHEADER_H
#include <iostream>

using namespace std;

class BadSize
{
private:
	int row1 = 0, row2 = 0;
	int col1 = 0, col2 = 0;
	int __case = 0;
public:
	BadSize(int row1, int row2, int col1, int col2)
	{
		this->row1 = row1;
		this->row2 = row2;
		this->col1 = col1;
		this->col2 = col2;
		__case = 0;
	}

	BadSize(int row, int col)
	{
		this->row1 = row;
		this->col1 = col;
		__case = 1;
	}

	int GetRow1()
	{
		return row1;
	}
	int GetRow2()
	{
		return row2;
	}
	int GetCol1()
	{
		return col1;
	}
	int GetCol2()
	{
		return col2;
	}
	void ShowError()
	{
		switch (__case)
		{
		case 0:
			cout << "Додавання і віднімання не можливе. Різна кількість рядків і стовпців " <<
				endl;
			break;
		case 1:
			cout << "Добуток неможливий. Рядків: " << row1 << "\n Стовпців: " << col1 <<
				endl;
			break;
		}
	}
};

class BadIndex
{
private:
	int row, col;
public:
	BadIndex(int row, int col) : row(row), col(col) {}

	int GetBadRow() { return row; }
	int GetBadCol() { return col; }
	void ShowError()
	{
		cout << "Індекс (" << row << ';' << col << ") не коректний" << endl;
	}
};

template <typename T>
class Array
{
	friend istream& operator>>(istream& in, Array<T>& arr)
	{
		for (int i = 0; i < arr.row; i++)
		{
			for (int j = 0; j < arr.col; j++)
			{
				in >> arr.p[i][j];
			}
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const Array<T>& arr)
	{
		for (int i = 0; i < arr.row; i++)
		{
			for (int j = 0; j < arr.col; j++)
			{
				out << arr.p[i][j] << ' ';
			}
			out << endl;
		}
		return out;
	}
	friend Array<T> operator+(const Array<T>& ar1, const Array<T>& ar2)
	{
		if (ar1.row == ar2.row && ar1.col == ar2.col)
		{
			Array<T> temp(ar1.row, ar1.col);
			for (int i = 0; i < ar1.row; i++)
			{
				for (int j = 0; j < ar1.col; j++)
				{
					temp.p[i][j] = ar1.p[i][j] + ar2.p[i][j];
				}
			}
			return temp;
		}
		else
		{
			throw BadSize(ar1.row, ar2.row, ar1.col, ar2.col);
		}
	}
	friend Array<T> operator-(const Array<T>& ar1, const Array<T>& ar2)
	{
		if (ar1.row == ar2.row && ar1.col == ar2.col)
		{
			Array<T> temp(ar1.row, ar1.col);
			for (int i = 0; i < ar1.row; i++)
			{
				for (int j = 0; j < ar1.col; j++)
				{
					temp.p[i][j] = ar1.p[i][j] - ar2.p[i][j];
				}
			}
			return temp;
		}
		else
		{
			throw BadSize(ar1.row, ar2.row, ar1.col, ar2.col);
		}
	}
	friend Array<T> operator*(const Array<T>& ar1, const Array<T>& ar2)
	{
		if (ar1.col == ar2.row)
		{
			Array<T> temp(ar1.row, ar2.col);
			for (int i = 0; i < ar1.row; i++)
			{
				for (int j = 0; j < ar2.col; j++)
				{
					temp.p[i][j] = 0;
					for (int k = 0; k < ar1.col; k++)
					{
						temp.p[i][j] = temp.p[i][j] + ar1.p[i][k] * ar2.p[k][j];
					}
				}
			}
			return temp;
		}
		else
		{
			throw BadSize(ar1.col, ar2.row);
		}
	}

private:
	T** p = nullptr;
	int row, col;

public:
	// конструктор по умолчанию
	Array()
	{
		row = 0;
		col = 0;
	}

	//конструктор 2
	Array(int row, int col) : row(row), col(col)
	{
		p = new T * [row];
		for (int i = 0; i < row; i++)
		{
			p[i] = new T[col];
		}
	}

	//конструктор копирования
	Array(const Array<T>& arr)
	{
		row = arr.row;
		col = arr.col;
		p = new T * [row];
		for (int i = 0; i < row; i++)
		{
			p[i] = new T[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j] = arr.p[i][j];
			}
		}
	}

	// дэструктор
	~Array()
	{
		if (p)
		{
			for (int i = 0; i < row; i++)
			{
				delete[] p[i];
			}
			delete[] p;
		}
	}

	const int GetRow() { return row; }
	const int GetCol() { return col; }

	const Array<T>& operator=(const Array<T>& arr)
	{
		if (&arr != this)
		{
			if (p)
			{
				for (int i = 0; i < arr.row; i++)
				{
					delete[] p[i];
				}
				delete[] p;
			}
			row = arr.row;
			col = arr.col;
			p = new T * [row];
			for (int i = 0; i < row; i++)
			{
				p[i] = new T[col];
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					p[i] = arr.p[i];
				}
			}
		}
		return *this;
	}

	T& operator()(int row, int col)
	{
		if ((row < 0 || col < 0) || (row >= this->row || col >= this->col))
		{
			throw BadIndex(row, col);
		}
		return p[row][col];
	}
};
#endif