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
		cout << "²ì'ÿ:\t" << name << endl << "Â³ê:\t" << age << endl;
	}
};

class Ñitizen : public Human
{
private:
	char country[40];
public:
	Ñitizen(const char* country, const char* name, int age) : Human(name, age)
	{
		strcpy(this->country, country);
	}

	void show() override
	{
		Human::show();
		cout << "Ãðîìàäÿíèí êðà¿íè:\t" << country << endl;
	}
};

class Student :public Ñitizen
{
private:
	char faculty[60];
	int grade;
public:
	Student(const char* faculty, int grade, const char* country, const char* name, int age) : Ñitizen(country, name, age)
	{
		strcpy(this->faculty, faculty);
		this->grade = grade;
	}

	void show() override
	{
		Ñitizen::show();
		cout << "Ñòóäåíò " << grade << " êóðñó" << endl << "Ôàêóëüòåòó:\t" << faculty << endl;
	}
};

class Employee : public Ñitizen
{
private:
	char position[60];
	int salary;
public:
	Employee(const char* pos, int salary, const char* country, const char* name, int age) : Ñitizen(country, name, age)
	{
		strcpy(position, pos);
		this->salary = salary;
	}

	void show() override
	{
		Ñitizen::show();
		cout << "Ïîñàäà:\t" << position << ", çàðïëàòíÿ:\t" << salary << endl;
	}
};

int main()
{
	SetConsoleOutputCP(1251);

	const int N = 5;

	Human* humans[N] = {
		new Human("²âàí", 20),
		new Ñitizen("Óêðà¿íà", "Âàñèëü", 25),
		new Student("Êîìï'þòåðíèõ íàóê", 2, "Óêðà¿íà", "Àíäð³é", 19),
		new Employee("Ìàðêåòîëîã", 3400, "Óêðà¿íà", "Ñòàí³ñëàâ", 23)
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