#include <iostream>
#include <conio.h>

#include <ctime>
#include <cstdlib>

#include <windows.h>
#include <iomanip>

#include <string>

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
	Player(bool player) : score(0)
	{
		if(player)
		{
			cout << ".:: Введите своё имя: ";
			cin >> name;
		}
		else
			name = "ИИ";
		for (int i = 0; i < MAX; i++)
		{
			stack[i].value_ = i + 1;
			stack[i].isUsed = false;
		}
	}
};

void charline(char = '-', int = 80);
//////////////////////////////////////////////////////
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Player* player = new Player(true);
	Player* enemy = new Player(false);

	_getch();
	return 0;
}

//.:: charline() :::::::::::::::::::::::::::::::::::::
void charline(char ch, int n)
{
	for (int i = 0; i < n; i++)
		cout << ch;
	cout << endl;
}