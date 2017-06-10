#include <iostream>
#include <Windows.h>
#include "Functions.h"

#define sizeArr 255

using namespace std;

HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	/*15. Написать программу, позволяющую формировать список студентов академической группы.
	Интерфейс программы должен предоставлять пользователю следующие возможности:
	a. добавление студентов в список;
	b. удаление студента из списка;
	c. модификация студента в списке;
	d. печать списка студентов;
	e. сортировка списка студентов;
	f. поиск студента;
	g. выход из программы.

	При разработке программы следует использовать ступенчатый динамический массив для хранения списка студентов
	(одномерный динамический массив указателей на строки).
	Для реализации функционала программы необходимо разработать следующую библиотеку функций:
	char **AddStudents(char **, int &);
	void Print(char **, int);
	void Sort(char **, int);
	char **RemoveStudent(char **, int &);
	char **EditStudent(char **, int);
	void FindStudent(char **, int);*/

	char **list = new char*[sizeArr];

	for (int i = 0; i < sizeArr; i++)
		list[i] = new char[sizeArr];

	int size = 0;

	SetConsoleCursorPosition(w, { 15, 0 });
	cout << "STUDENT LIST | COUNT: ";
	SetConsoleTextAttribute(w, 10);
	cout << size;
	SetConsoleTextAttribute(w, 7);
	frame();

	SetConsoleCursorPosition(w, { 75, 0 });
	SetConsoleTextAttribute(w, 10);
	cout << "MENU";
	SetConsoleTextAttribute(w, 7);
	menu(list, size);

	SetConsoleCursorPosition(w, { 0, 23 });
	cout << endl;
}