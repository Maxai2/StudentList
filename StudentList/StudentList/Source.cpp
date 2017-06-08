#include <iostream>
#include <Windows.h>
#include "Functions.h"

using namespace std;

HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	SetConsoleCursorPosition(w, { 30, 0 });
	cout << "STUDENT LIST";
	frame();
}
