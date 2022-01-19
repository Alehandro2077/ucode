#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>
using namespace std;

class BadSize
{
private:
	int row1 = 0, row2 = 0;
	int col1 = 0, col2 = 0;
	int cas = 0;
public:
	BadSize(int row1, int col1, int row2, int col2)
	{
		this->row1 = row1;
		this->col1 = col1;
		this->row2 = row2;
		this->col2 = col2;
		cas = 1;
	}
	BadSize(int row, int col)
	{
		row1 = row;
		col1 = col;
		cas = 2;
	}
	void ShowError()
	{
		switch (cas)
		{
		case 1:
			cout << "Sum or diff impossible, different amount of rows & cols" << endl;
			cout << "First array. Rows " << row1 << ", cols " << col1 << endl;
			cout << "Second array. Rows " << row2 << ", cols " << col2 << endl;
			break;
		case 2:
			cout << "Multiplication is impossible" << endl;
			cout << "First array cols " << col1 << "\nSecond array rows " << row1 << endl;
			break;
		}
	}
};

class BadIndex
{
private:
	int row, col;
public:
	BadIndex(int row, int col)
	{
		this->row = row;
		this->col = col;
	}
	void ShowError()
	{
		cout << "Index (" << row << ';' << col << ") doesn't exist" << endl;
	}
};

class MyVector
{
	friend ostream& operator<<(ostream& out, const MyVector& v)
	{
		for (const auto& row : v.matrix)
		{
			for (const auto& val : row)
			{
				out << val << ' ';
			}
			out << endl;
		}
		return out;
	}
	friend istream& operator>>(istream& in, MyVector& v)
	{
		for (auto& row : v.matrix)
		{
			for (auto& val : row)
			{
				cin >> val;
			}
		}
		return in;
	}
	friend MyVector operator+(MyVector& v1, MyVector v2)
	{
		if (v1.matrix.size() == v2.matrix.size() && v1.matrix[0].size() == v2.matrix[0].size())
		{
			MyVector sum(v1.matrix.size(), v1.matrix[0].size());
			for (size_t i = 0; i < v1.matrix.size(); i++)
			{
				for (size_t j = 0; j < v1.matrix[i].size(); j++)
				{
					sum.matrix[i][j] = v1.matrix[i][j] + v2.matrix[i][j];
				}
			}
			return sum;
		}
		else
		{
			throw BadSize(v1.matrix.size(), v1.matrix[0].size(), v2.matrix.size(), v2.matrix[0].size());
		}
	}
	friend MyVector operator-(MyVector& v1, MyVector v2)
	{
		if (v1.matrix.size() == v2.matrix.size() && v1.matrix[0].size() == v2.matrix[0].size())
		{
			MyVector sum(v1.matrix.size(), v1.matrix[0].size());
			for (size_t i = 0; i < v1.matrix.size(); i++)
			{
				for (size_t j = 0; j < v1.matrix[i].size(); j++)
				{
					sum.matrix[i][j] = v1.matrix[i][j] - v2.matrix[i][j];
				}
			}
			return sum;
		}
		else
		{
			throw BadSize(v1.matrix.size(), v1.matrix[0].size(), v2.matrix.size(), v2.matrix[0].size());
		}
	}
	friend MyVector operator*(MyVector& v1, MyVector v2)
	{
		if (v1.matrix[0].size() == v2.matrix.size())
		{
			MyVector sum(v1.matrix.size(), v2.matrix[0].size());
			for (size_t i = 0; i < v1.matrix.size(); i++)
			{
				for (size_t j = 0; j < v2.matrix[0].size(); j++)
				{
					int _sum = 0;
					for (size_t k = 0; k < v1.matrix[0].size(); k++)
					{
						_sum = _sum + v1.matrix[i][k] * v2.matrix[k][j];
					}
					sum.matrix[i][j] = _sum;
				}
			}
			return sum;
		}
		else
		{
			throw BadSize(v1.matrix[0].size(), v2.matrix.size());
		}
	}
private:
	vector<vector<int>> matrix;
public:
	MyVector(int row, int col);
	MyVector(initializer_list<vector<int>> list);
	MyVector() {}
	int GetRow() const { return matrix.size(); }
	int GetCol() const { return matrix[0].size(); }
	int& operator()(const unsigned int& row, const unsigned int& col);
};

#endif 





