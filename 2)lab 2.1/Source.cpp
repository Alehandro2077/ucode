#pragma warning(disable:4996)

#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

class Human
{
private:
	char name[40];
	int age;
public:
	Human(const char* name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}

	virtual void show()
	{
		cout << "��'�:\t" << name << endl << "³�:\t" << age << endl;
	}
};

class �itizen : public Human
{
private:
	char country[40];
public:
	�itizen(const char* country, const char* name, int age) : Human(name, age)
	{
		strcpy(this->country, country);
	}

	void show() override
	{
		Human::show();
		cout << "���������� �����:\t" << country << endl;
	}
};

class Student :public �itizen
{
private:
	char faculty[60];
	int grade;
public:
	Student(const char* faculty, int grade, const char* country, const char* name, int age) : �itizen(country, name, age)
	{
		strcpy(this->faculty, faculty);
		this->grade = grade;
	}

	void show() override
	{
		�itizen::show();
		cout << "������� " << grade << " �����" << endl << "����������:\t" << faculty << endl;
	}
};

class Employee : public �itizen
{
private:
	char position[60];
	int salary;
public:
	Employee(const char* pos, int salary, const char* country, const char* name, int age) : �itizen(country, name, age)
	{
		strcpy(position, pos);
		this->salary = salary;
	}

	void show() override
	{
		�itizen::show();
		cout << "������:\t" << position << ", ���������:\t" << salary << endl;
	}
};

int main()
{
	SetConsoleOutputCP(1251);

	const int N = 5;

	Human* humans[N] = {
		new Human("����", 20),
		new �itizen("������", "������", 25),
		new Student("����'������� ����", 2, "������", "�����", 19),
		new Employee("����������", 3400, "������", "��������", 23)
	};

	for (int i = 0; i < N; i++)
	{
		humans[i]->show();
		cout << endl;
	}
	for (int i = 0; i < N; i++)
	{
		delete humans[i];
	}
	
	system("pause");
}