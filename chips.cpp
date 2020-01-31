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
	bool isUsed_;
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
			stack[i].isUsed_ = false;
		}
	}
	//.:: Methods_of_class
	int GetValue(bool);
	void ShowAvailableChips();
	bool CheckChipValue(int, bool);
};
//////////////////////////////////////////////////////
bool Player:: CheckChipValue(int choice, bool player)
{
	if(choice > 0 && choice < 7)
	{
		if(!stack[choice - 1].isUsed_)
			return true;
		else
		{
			if(player)
				cout << ".:: Фишка была использована ранее!" << endl;
			return false;
		}
	}
	else
	{
		cout << ".:: Такой фишки не существует!" << endl;
		return false;
	}
}
//----------------------------------------------------
void Player:: ShowAvailableChips()
{
	cout << "[";
	for (int i = 0; i < MAX; i++)
	{
		if(!stack[i].isUsed_)
			cout << stack[i].value_ << ' ';
	}
	cout << "]: ";
}
//----------------------------------------------------
int Player::GetValue(bool player)
{
	int choice = 0;
	if(player)
	{
		while(true)
		{
			cout << ".:: Выберите фишку из доступных ";
			ShowAvailableChips();
			cin >> choice;
			if(CheckChipValue(choice, true))
				break;
		}
	}
	else
	{
		while(true)
		{
			choice = rand() % 6 + 1;
			if(CheckChipValue(choice, false))
				break;
		}
	}
	stack[choice - 1].isUsed_ = true;
	return choice;
}
//----------------------------------------------------
void charline(char = '-', int = 80);
//////////////////////////////////////////////////////
int main()
{
	system("mode con cols=80 lines=25");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Player* player = new Player(true);
	Player* enemy = new Player(false);

	system("cls");

	int round, playerChoice, enemyChoice;
	round = playerChoice = enemyChoice = 0;

	srand(time(NULL));

	while(round < 6)
	{
		cout << setw(75) << ".:: раунд " << ++round << endl;
		playerChoice = player -> GetValue(true);
		enemyChoice = enemy -> GetValue(false);
	}

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