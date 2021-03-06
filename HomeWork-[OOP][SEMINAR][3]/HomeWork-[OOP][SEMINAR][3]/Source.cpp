﻿/*Създайте клас Human с две полета - име и фамилия, клас Student, който наследява Human и добавя ново поле - grade (double),
клас Worker, също наследява Human и има нови полета weekSalary - седмично възнаграждение и workHoursPerDay - колко часа работи на ден
и функция moneyPerHour(), която връща колко пари печели работникът на час. Имплементирайте голяма четворка където е нужно.
След като сте имплементирали класовете, в main функцията декларирайте масив от 10 ученици и го сортирайте по grade във възходящ ред.
Декларирайте втори масив от 10 работници и го сортирайте по пари, изкарани на час в низходящ ред.
Накрая обединете двата списъка в един и го сортирайте по име.*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include <iterator>
#include <sstream>
#include <map>
#include <list>
#include <utility>
using namespace std;
class Human {
	char* name;
	char* surname;
public:
	Human(char *_name = " ", char* _surname = " ") {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		surname = new char[strlen(_surname) + 1];
		strcpy(surname, _surname);
	}
	Human(const Human& other) {
		name = new char[strlen(other.getName()) + 1];
		strcpy(name, other.getName());
		surname = new char[strlen(other.getSurname()) + 1];
		strcpy(surname, other.getSurname());
	};
	~Human() {
		delete[] name;
		delete[] surname;
	}
	char *getName() const {
		return name;
	}
	char *getSurname() const {
		return surname;
	}
	Human& operator=(const Human & other) {
		if (this != &other) {
			delete[] name;
			name = new char[strlen(other.getName()) + 1];
			strcpy(name, other.getName());
			delete[] surname;
			surname = new char[strlen(other.getSurname()) + 1];
			strcpy(surname, other.getSurname());
		}
		return *this;
	}
};
class Student :public Human {
	double grades;
public:
	Student(char* _name, char* _surname, double _grades = 0) :Human(_name, _surname) {
		grades = _grades;
	}
	bool operator < (const Student& str) const
	{
		return (this->grades < str.getGrades());
	}

	double getGrades() const {
		return grades;
	}
	void printStudent() {
		cout << "Grade=" << getGrades() << endl;
		cout << "Name:" << getName() << endl;
		cout << "Surname:" << getSurname() << endl;
	}
};
class Worker : public Human {
	int WeekSalary;
	int workHoursPerDay;
public:
	Worker(char* _name, char* _surname, int _WeekSalary = 0, int _workHoursPerDay = 0) :Human(_name, _surname) {
		WeekSalary = _WeekSalary;
		workHoursPerDay = _workHoursPerDay;
	}
	double moneyPerHour() {
		return getWeekSalary() / 7 * getworkHoursPerDay();
	}
	int getWeekSalary() const {
		return WeekSalary;
	}
	int getworkHoursPerDay() const {
		return workHoursPerDay;
	}
	bool operator < (const Worker& str) const
	{
		return (this->WeekSalary > str.getWeekSalary());
	}
};

void fillStudent(vector<Student>& newMyClass)
{
	char name[30];
	char surname[30];
	int grade;
	cout << "How many students are in your class? ";
	int classSize;
	cin >> classSize;
	for (int i = 0; i < classSize; i++)
	{
		cout << "Enter Student's name: ";
		cin >> name;
		cout << "Enter Student's surname: ";
		cin >> surname;
		cout << "Enter Grades";
		cin >> grade;

		Student newStudent(name, surname, grade);
		newMyClass.push_back(newStudent);
		cout << endl;
	}
}
void fillWorker(vector<Worker>& newMyClass)
{
	char name[30];
	char surname[30];
	int WeekSalary;
	int workHoursPerDay;
	cout << "How many workers are in your class? ";
	int classSize;
	cin >> classSize;
	for (int i = 0; i < classSize; i++)
	{
		cout << "Enter Worker's name: ";
		cin >> name;
		cout << "Enter Worker's surname: ";
		cin >> surname;
		cout << "Enter WeekSalary";
		cin >> WeekSalary;
		cout << "Enter workHoursPerDay";
		cin >> workHoursPerDay;

		Worker newWorker(name, surname, WeekSalary, workHoursPerDay);
		newMyClass.push_back(newWorker);
		cout << endl;
	}
}
void printStudent(vector<Student>& newMyClass) {
	unsigned int size = newMyClass.size();
	for (unsigned int i = 0; i < size; i++) {
		cout << "Student Name: " << newMyClass[i].getName() << endl;
		cout << "Student Surname: " << newMyClass[i].getSurname() << endl;
		cout << "Student Grade: " << newMyClass[i].getGrades() << endl;
	}
}
void printWorker(vector<Worker>& newMyClass) {
	unsigned int size = newMyClass.size();
	for (unsigned int i = 0; i < size; i++) {
		cout << "Worker Name: " << newMyClass[i].getName() << endl;
		cout << "Worker Surname: " << newMyClass[i].getSurname() << endl;
		cout << "Worker weekSalary: " << newMyClass[i].getWeekSalary() << endl;
		cout << "Worker workHoursPerDay: " << newMyClass[i].getworkHoursPerDay() << endl;
	}
}

int main()
{
	vector<Student> students;
	fillStudent(students);
	printStudent(students);
	sort(students.begin(), students.end());
	cout << "endl";
	for (int i = 0; i < 10; i++)
		cout << "Lets Sort the Vector :) " << endl;
	cout << endl;
	printStudent(students);

	vector<Worker> workers;
	fillWorker(workers);
	printWorker(workers);
	sort(workers.begin(), workers.end());
	cout << "endl";
	for (int i = 0; i < 10; i++)
		cout << "Lets Sort the Vector :) " << endl;
	cout << endl;
	printWorker(workers);



	system("pause");
	return 0;
}
/*
int main()
{
Student students[10] = { Student(11 , "BEmil" , "Todorovv"),
Student(2 , "EDmil" , "Todorovv"),
Student(73 , "HEmil" , "Todorovv"),
Student(44 , "JEmil" , "Todorovv"),
Student(5 , "IEmil" , "Todorovv"),
Student(62 , "OEmil" , "Todorovv"),
Student(71 , "FEmil" , "Todorovv"),
Student(80 , "AEmil" , "Todorovv"),
Student(9 , "HEmil" , "Todorovv"),
Student(115 , "HHEmil" , "Todorovv")
};
sort(begin(students), end(students)); // probvah go ot liubopitstvo


for (int i = 0; i < 10; i++)
{
students[i].print();
cout << endl;
}

Worker workers[10] = { Worker("QEmil" , "Todorovv",200,4),
Worker("REmil" , "Todorovv",200,5),
Worker("CEmil" , "Todorovv",300,6),
Worker("BEmil" , "Todorovv",400,7),
Worker("REmil" , "Todorovv",500,8),
Worker("FEmil" , "Todorovv",600,9),
Worker("NEmil" , "Todorovv",700,8),
Worker("GEmil" , "Todorovv",800,8),
Worker("HEmil" , "Todorovv",900,8),
Worker("AEmil" , "Todorovv",1000,8)
};
int minimalPosition; //normalna sortirovka
for (int i = 0; i < 10; i++)
{
minimalPosition = i;
for (int j = i + 1; j < 10; j++)
{
if (workers[j].MoneyPerHour() > workers[minimalPosition].MoneyPerHour())
{
minimalPosition = j;
}
}
if (minimalPosition != i)
{
Worker flag = workers[i];
workers[i] = workers[minimalPosition];
workers[minimalPosition] = flag;
}
}
for (int i = 0; i < 10; i++)
{
workers[i].print();
cout << endl;
}


cout << "------------------------------------------------------------" << endl;
cout << endl;
Human** doubleArray = new Human*[20];
for (int i = 0; i < 10; i++)
{
doubleArray[i] = new Worker(workers[i]);
}
for (int i = 10; i < 20; i++)
{
doubleArray[i] = new Student(students[i - 10]);
}
// normalna sortirovka
short k;
Human* max;

for (int i = 0; i < 19; i++) {
max = doubleArray[i];
k = i;
for (int j = i + 1; j < 20; j++)
if (strcmp(doubleArray[j]->getFirstName(), max->getFirstName()) == 0) {
if (strcmp(doubleArray[j]->getLastName(), max->getLastName()) < 0) {
max = doubleArray[j];
k = j;
}
}
else {
if (strcmp(doubleArray[j]->getFirstName(), max->getFirstName()) < 0) {
max = doubleArray[j];
k = j;
}

}
Human* swap;
swap = doubleArray[k];
doubleArray[k] = doubleArray[i];
doubleArray[i] = swap;
}
for (int i = 0; i < 20; i++)
{
doubleArray[i]->print();
cout << endl;
}
return 0;
}*/