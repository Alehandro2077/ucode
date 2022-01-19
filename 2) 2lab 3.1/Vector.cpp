#include <algorithm>
#include <iostream>
#include "Vector.h"

MyVector::MyVector(int row, int col)
{
	matrix = vector<vector<int>>(row);
	for (auto& row : matrix)
		row.resize(col);
}
int& MyVector::operator()(const unsigned int& row, const unsigned int& col)
{
	if ((row < 0 || col < 0) || (row >= matrix.size() || col >= matrix[0].size()))
	{
		throw BadIndex(row, col);
	}
	else
	{
		return matrix.at(row).at(col);
	}
}
MyVector::MyVector(initializer_list<vector<int>> list)
{
	matrix = move(list);
}