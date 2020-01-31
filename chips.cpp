#include <iostream>
#include <conio.h>

#include <ctime>
#include <cstdlib>

#include <windows.h>
#include <iomanip>

using namespace std;

const int MAX = 6;

struct Chip
{
	int value_;
	bool isUsed;
};

class Player
{
private:
	string name;
	Chip stack[MAX];
	int score;
public:
	//.:: Constructor
	Player(string Name) : score(0)
	{
		name = Name;
		for (int i = 0; i < MAX; i++)
		{
			stack[i].value_ = i + 1;
			stack[i].isUsed = false;
		}
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	_getch();
	return 0;
}