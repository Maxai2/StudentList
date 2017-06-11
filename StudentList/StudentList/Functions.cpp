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

void clearTable()
{
	int sLength = 1, fLength = 59, sWidth = 2, fWidth = 21;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			SetConsoleCursorPosition(h, { j,i });
			cout << " ";
		}
	}
}

void count(int size)
{
	SetConsoleCursorPosition(h, { 37, 0 });
	cout << "  ";
	SetConsoleCursorPosition(h, { 37, 0 });
	SetConsoleTextAttribute(h, 10);
	cout << size;
	SetConsoleTextAttribute(h, 7);
}

void clearMenu()
{
	int sLength = 62, fLength = 90, sWidth = 1, fWidth = 10;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			SetConsoleCursorPosition(h, { j,i });
			cout << " ";
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
	for (short i = 24; i < 30; i++)
	{
		SetConsoleCursorPosition(h, { 0, i });
		for (int k = 0; k < 100; k++)
			cout << " ";
	}
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
	clearTable();
	if (size != 0)
		for (short i = 0; i < size; i++)
		{
			SetConsoleCursorPosition(h, { 1, temp * 2 });
			cout << "\t\t\t\t\t\t";
			SetConsoleCursorPosition(h, { 1, temp * 2 });
			cout << i + 1 << ". " << arr[i];
			SetConsoleTextAttribute(h, menuColor);
			delimetr(temp * 2 + 1);
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

char **RemoveStudent(char **arr, int &size)
{
	int num = 0;
	char *temp;
	SetConsoleCursorPosition(h, { 0, 24 });
	cout << "Enter the order number of student for remove: ";
	SetConsoleTextAttribute(h, 10);
	cin >> num;
	SetConsoleTextAttribute(h, 7);
	num--;
	while (true)
	{
		temp = arr[num];
		arr[num] = arr[num + 1];
		arr[num + 1] = temp;
		
		if (num == size - 1)
			break;
		else
			num++;
	}
	size--;
	return arr;

}

char **EditStudent(char **arr, int size)
{
	int num = 0, key;
	SetConsoleCursorPosition(h, { 0, 24 });
	cout << "Enter the order number of student for editing: ";
	SetConsoleTextAttribute(h, 10);
	cin >> num;
	num--;
	SetConsoleTextAttribute(h, 7);
	cleanRedaktPlace();
	SetConsoleCursorPosition(h, { 0, 24 });
	cout << "Old name: ";
	SetConsoleTextAttribute(h, 10);
	cout << arr[num] << endl;
	SetConsoleTextAttribute(h, 7);
	cout << "Input new name with modification press (e) or (esc) for return menu: ";
	cin.getline(arr[num], nameLength);

	//while (true)
	//{
	//	key = getch();

	//	if (key == 27) // esc
	//		return arr;
	//	else if (key == 101) // e
	//	{
	//		cleanRedaktPlace();
	//		SetConsoleCursorPosition(h, { 0, 24 });
	//		cout << "Old name: ";
	//		SetConsoleTextAttribute(h, 10);
	//		cout << arr[num] << endl;
	//		SetConsoleTextAttribute(h, 7);
	//		cout << "Input new name : ";
	//		cin.getline(arr[num], nameLength);
	//	}
	//}
	return arr;
}

void FindStudent(char **arr, int size)
{
	char *temp = new char[nameLength];
	bool check = true;
	short row = 25;
//	int tempIndex = 0;
	SetConsoleCursorPosition(h, { 0, 24 });
	cout << "Enter the name or part of name: ";
	cin.getline(temp, nameLength);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; arr[i][j] != '\0'; j++)
		{
			if (arr[i][j] == temp[0])
			{
				for (int k = 0; temp[k] != '\0'; k++, j++)
				{
					if (arr[i][j] != temp[k])
						check = false;
				}
				if (check)
				{ 
					SetConsoleCursorPosition(h, { 0, row });
					cout << arr[i];
					row++;
					break;
				}
			}
		}
	}
	cout << endl;
	system("pause");
}

void menu(char **list, int size)
{
	int sel = 0, key = 0;
	clearMenu();
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
				count(size);
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
				count(size);
				cleanRedaktPlace();
				Sort(list, size);
				menu(list, size);
				break;
			}
			else if (key == 13 && sel == 1)
			{
				RemoveStudent(list, size);
				count(size);
				cleanRedaktPlace();
				Print(list, size);
				menu(list, size);
				break;
			}
			else if (key == 13 && sel == 2)
			{
				EditStudent(list, size);
				cleanRedaktPlace();
				Print(list, size);
				menu(list, size);
				break;
			}
			else if (key == 13 && sel == 3)
			{
				FindStudent(list, size);
				cleanRedaktPlace();
				menu(list, size);
				break;
			}
			else if (key == 13 && sel == 4)
				break;
		}
}