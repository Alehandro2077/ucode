#include <iostream>
#include <windows.h>

using namespace std;

class Array
{
	friend istream& operator>>(istream& in, Array& arr)
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
	friend ostream& operator<<(ostream& out, const Array& arr)
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
	friend Array operator+(const Array& ar1, const Array& ar2)
	{
		if (ar1.row == ar2.row && ar1.col == ar2.col)
		{
			Array temp(ar1.row, ar1.col);
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
	friend Array operator-(const Array& ar1, const Array& ar2)
	{
		if (ar1.row == ar2.row && ar1.col == ar2.col)
		{
			Array temp(ar1.row, ar1.col);
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
	friend Array operator*(const Array& ar1, const Array& ar2)
	{
		if (ar1.col == ar2.row)
		{
			Array temp(ar1.row, ar2.col);
			for (int i = 0; i < ar1.row; i++)
			{
				for (int j = 0; j < ar2.col; j++)
				{
					temp.p[i][j] = 0;
					for (int k = 0; k < ar1.col; k++)
					{
						temp.p[i][j] += ar1.p[i][k] * ar2.p[k][j];
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
	int** p = nullptr;
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
		p = new int* [row];
		for (int i = 0; i < row; i++)
		{
			p[i] = new int[col];
		}
	}

	//конструктор копирования
	Array(const Array& arr)
	{
		row = arr.row;
		col = arr.col;
		p = new int* [row];
		for (int i = 0; i < row; i++)
		{
			p[i] = new int[col];
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

	class BadSize
	{
	private:
		int row1 = 0, row2 = 0;
		int col1 = 0, col2 = 0;
	public:
		BadSize(int row1, int row2, int col1, int col2)
		{
			this->row1 = row1;
			this->row2 = row2;
			this->col1 = col1;
			this->col2 = col2;
		}

		BadSize(int row, int col)
		{
			this->row1 = row;
			this->col1 = col;
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
	};

	class BadIndex
	{
	private:
		int row, col;
	public:
		BadIndex(int row, int col) : row(row), col(col) {}

		int GetBadRow() { return row; }
		int GetBadCol() { return col; }
	};

	int& operator()(int row, int col)
	{
		if ((row < 0 || col < 0) || (row >= this->row || col >= this->col))
		{
			throw BadIndex(row, col);
		}
		return p[row][col];
	}
};

void Func(Array& arr)
{
	for (int i = 0; i < arr.GetRow(); i++)
	{
		for (int j = 0; j < arr.GetCol(); j++)
		{
			if (arr(i, j) % 2 != 0)
			{
				arr(i, j) *= 2;
			}
		}
	}
}

int main()
{
	SetConsoleOutputCP(1251);

	int row, col;
	cout << "Введіть кількість рядків та стовпців першого масиву: ";
	cin >> row >> col;

	Array arr1(row, col);
	cout << "Введіть елементи першого масиву:" << endl;
	cin >> arr1;

	cout << "Введіть кількість рядків та стовпців другого масиву: ";
	cin >> row >> col;

	Array arr2(row, col);
	cout << "Введіть елементи першого масиву:" << endl;
	cin >> arr2;

	system("cls");

	cout << "Перший масив\n" << endl << arr1 << endl;
	cout << "Другий масив\n" << endl << arr2 << endl;

	try
	{
		cout << "Сума першої та другої матриці: " << endl;
		cout << arr1 + arr2 << endl;
		cout << "Різниця першого та другого масиву:" << endl;
		cout << arr1 - arr2 << endl;
		cout << endl;
	}
	catch (Array::BadSize& e)
	{
		cout << "Складанная та віднімання неможливе, різна кількість рядків та стовпців" << endl;
		cout << "Рядки I та II матриці відповідно: " << e.GetRow1() << ',' << e.GetRow2() << endl;
		cout << "Стовпці I та II матриці відповідно: " << e.GetCol1() << ',' << e.GetCol2() << endl;
		cout << endl;
	}
	try
	{
		cout << "Добуток матриць: " << endl;
		cout << arr1 * arr2 << endl;;
	}
	catch (Array::BadSize& e)
	{
		cout << "Різна кількість стовпців та рядків" << endl;
		cout << "Кількість стовпців I масиву: " << e.GetCol1() << endl;
		cout << "Кількість рядків II масиву: " << e.GetRow1() << endl;
		cout << endl;
	}
	try
	{
		cout << "Елемент (1;0): " << arr1(1, 0) << endl;
		cout << "Елемент (0;1): " << arr1(0, 1) << endl;
		cout << "Елемент (5;6): " << arr1(5, 6) << endl;
		cout << endl;
	}
	catch (Array::BadIndex& e)
	{
		cout << "Елемент з індексом (" << e.GetBadRow() << ';' << e.GetBadCol() << ") не існує" << endl;
		cout << endl;
	}

	cout << "Масив до виконання функції:" << endl;
	cout << arr1 << endl;
	cout << endl;
	cout << "Масив після виконання функції(усі елементи з непарними значеннями збільшені в два рази):" << endl << endl;
	Func(arr1);
	cout << arr1 << endl;

	system("pause");
	return 0;
}