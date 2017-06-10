#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

#define defaultColor 7
#define menuColor 11
#define nameLength 255

void frame()
{
	int sLength = 0, fLength = 60, sWidth = 1, fWidth = 22;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			SetConsoleCursorPosition(h, { j,i });

			if (i == sWidth || i == fWidth - 1)
				cout << char(178);
			else if (j == sLength && sWidth < i && i < fWidth)
				cout << char(178);
			else if (j == fLength - 1 && sWidth < i && i < fWidth)
				cout << char(178);
		}
	}
}

void delimetr(short row)
{
	SetConsoleCursorPosition(h, { 1,row });
	for (int i = 0; i < 40; i++)
		cout << char(196);
}

int len(char **arr, int row)
{
	int length = 0;
	while (arr[row][length] != '\0')
		length++;
	return length;
}

void cleanRedaktPlace()
{
	SetConsoleCursorPosition(h, { 0, 24 });
	for (int i = 0; i < 100; i++)
		cout << " ";
}

char **AddStudents(char **arr, int &size)
{
	SetConsoleCursorPosition(h, { 0, 24 });
	cout << "Input name(FirstN LastN FatherN): ";
	SetConsoleTextAttribute(h, 10);
	cin.getline(arr[size], nameLength);
	SetConsoleTextAttribute(h, 7);
	size++;
	return arr;
}

void Print(char **arr, int size)
{
	short temp = 1;
	for (short i = 0; i < size; i++)
	{
		SetConsoleCursorPosition(h, { 1, temp * 2 });
		cout << "\t\t\t\t\t\t";
		SetConsoleCursorPosition(h, { 1, temp * 2 });
		cout << i + 1 << ". " << arr[i];
		SetConsoleTextAttribute(h, menuColor);
		delimetr(size * 2 + 1);
		SetConsoleTextAttribute(h, defaultColor);
		temp++;
	}
}

void Sort(char **arr, int size)
{
	char *temp;
	if (size == 1)
		Print(arr, size);
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; arr[i + 1][j] != '\0'; j++)
			{
				if (arr[i][j] > arr[i + 1][j])
				{
					temp = arr[i + 1];
					arr[i + 1] = arr[i];
					arr[i] = temp;
					i = size;
					break;
				}
				else if (arr[i][j] < arr[i + 1][j])
				{
					i = size;
					break;
				}
				
			}
		}
				
		Print(arr, size);
	}
}

void menu(char **list, int size)
{
	int sel = 0, key = 0;

	if (size == 0)
		while (true)
		{
			SetConsoleCursorPosition(h, { 72, 2 });

			if (sel == 0)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Add student";

			SetConsoleTextAttribute(h, defaultColor);
			SetConsoleCursorPosition(h, { 75, 3 });
			if (sel == 1)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Exit";
			SetConsoleTextAttribute(h, defaultColor);

			key = getch();
			if (key == 0)
				key = getch();

			if (key == 72 && sel == 1) // Up
				sel--;
			else if (key == 80 && sel == 0) // Down
				sel++;
			else if (key == 13 && sel == 0)
			{
				AddStudents(list, size);
				cleanRedaktPlace();
				Sort(list, size);
				menu(list, size);
				break;
			}
			else if (key == 13 && sel == 1)
				break;
		}
	else
		while (true)
		{
			SetConsoleCursorPosition(h, { 72, 2 });

			if (sel == 0)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Add student";

			SetConsoleTextAttribute(h, defaultColor);
			SetConsoleCursorPosition(h, { 70, 3 });

			if (sel == 1)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Remove student";

			SetConsoleTextAttribute(h, defaultColor);
			SetConsoleCursorPosition(h, { 67, 4 });

			if (sel == 2)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Student modification";

			SetConsoleTextAttribute(h, defaultColor);
			SetConsoleCursorPosition(h, { 70, 5 });

			if (sel == 3)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Student search";

			SetConsoleTextAttribute(h, defaultColor);
			SetConsoleCursorPosition(h, { 75, 6 });

			if (sel == 4)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Exit";

			SetConsoleTextAttribute(h, defaultColor);

			key = getch();
			if (key == 0)
				key = getch();

			if (key == 72 && 0 < sel) // Up
				sel--;
			else if (key == 80 && sel < 4) // Down
				sel++;
			else if (key == 13 && sel == 0)
			{
				AddStudents(list, size);
				cleanRedaktPlace();
				Sort(list, size);
				menu(list, size);
				break;
			}
			else if (key == 13 && sel == 4)
				break;
		}
}

