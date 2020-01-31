#include <iostream>
#include <conio.h>

#include <ctime>
#include <cstdlib>

#include <windows.h>
#include <iomanip>

using namespace std;

struct Chip
{
	int value_;
	bool isUsed;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	_getch();
	return 0;
}