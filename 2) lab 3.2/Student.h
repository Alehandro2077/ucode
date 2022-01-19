#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

class Student
{
private:
	unsigned int ID;
	string surname;
	vector<unsigned short int> marks;

public:
	Student () {}	
	Student(unsigned int ID, string surname, vector<unsigned short int> marks)
	{
		this->ID = ID;
		this->surname = surname;
		this->marks = marks;
	}

	unsigned int GetID() const { return ID; }
	string GetSurname() const { return surname; }
	vector<unsigned short int> GetMarks() const { return marks; }

	void SetID(unsigned int ID) { this->ID = ID; }
	void SetSurname(string surname) { this->surname = surname; }
	void SetMarks(vector<unsigned short int> marks) { this->marks = marks; }
	void Show()
	{
		cout << "ID number: " << ID << endl;
		cout << "Surname: " << surname << endl;
		cout << "Marks: ";
		for (int x : marks)
			cout << x << ' ';
		cout << "Average mark: " << AvMark() << endl;
		cout << endl;
	}

	double AvMark() const
	{
		double av = 0;
		for (auto& x : marks)
			av += x;
		return av / marks.size();
	}

	bool ChooseCond()
	{
		if (AvMark() >= 64 && AvMark() <= 74)
			return 1;

		return 0;
	}
};

class Group
{
	friend ostream& operator<<(ostream& out, const Group& gr)
	{
		for (Student student : gr.group)
		{
			student.Show();
		}
		return out;
	}

	friend istream& operator>>(istream& in, Group& gr)
	{
		unsigned int ID;
		string surname;
		unsigned short int mark;
		vector<unsigned short int> marks;

		cout << "Input ID: ";
		in >> ID;
		cout << "Input surname: ";
		in >> surname;
		cout << "Input 4 marks: ";
		for (int i = 0; i < 4; i++)
		{
			while (true)
			{
				in >> mark;
				if (mark < 0 || mark > 100)
				{
					cout << "Invalid mark" << endl;
					continue;
				}
				break;
			}
			marks.push_back(mark);
		}
		Student student(ID, surname, marks);
		gr.group.push_back(student);
		return in;
	}

private:
	vector <Student> group;

public:

	int GetGrSize() const { return group.size(); }
	vector <Student> GetGr() const { return group; }

	void SortSt()
	{
		sort(group.begin(), group.end(), [](Student& s1, Student& s2) {return s1.GetSurname() < s2.GetSurname(); });
	}

	void Cond()
	{
		for_each(group.begin(), group.end(), [](Student st) {if (st.ChooseCond()) st.Show(); });
	}

	void Queue()
	{
		priority_queue<Student> pq;
		
		
		for (auto& x : group)
			pq.push(x);
		while (pq.size())
		{
			cout << "Student\t" << pq.top().GetSurname() << "\twith average mark\t" << pq.top().AvMark();
			cout << "\thas been deleted" << endl;
			pq.pop();
		}
	}

};

bool operator<(const Student& s1, const Student& s2)
{
	return s1.AvMark() < s2.AvMark();
}

#endif 

