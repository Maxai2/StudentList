#include <iostream>
#include <Windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void frame()
{
	int sLength = 0, fLength = 10, sWidth = 1, fWidth = 10;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			SetConsoleCursorPosition(h, { i,j });

			if (i == sWidth || i == fWidth)
				cout << char(179);
		}
	}

}