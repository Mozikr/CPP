#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define BOARD_SIZE 3
#define BLANK_SPACE '_'
char BOARD[BOARD_SIZE][BOARD_SIZE];

void Initialize()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			BOARD[i][j] = BLANK_SPACE;
		}
	}
}

void Render()
{
	system("cls");

	cout << "  ";
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		cout << i << ' ';
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			cout << BOARD[i][j] << " ";
		}
		cout << endl;
	}
}

bool HasWon(char playerSymbol, int x, int y)
{
	bool result = true;

	// wiersze
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (BOARD[x][i] != playerSymbol)
		{
			result = false;
			break;
		}
	}

	if (result) return true;

	result = true;

	// kolumny
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (BOARD[i][y] != playerSymbol)
		{
			result = false;
			break;
		}
	}

	if (result) return true;

	result = true;

	// skosy
	if (x == y || x + y == BOARD_SIZE - 1)
	{
		result = true;
		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			if (BOARD[i][i] != playerSymbol)
			{
				result = false;
				break;
			}
		}
		if (result) return true;
		result = true;
		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			if (BOARD[i][BOARD_SIZE - 1 - i] != playerSymbol)
			{
				result = false;
				break;
			}
		}
		if (result) return true;
	}

	return false;
}


bool PlayerInput(char playerSymbol)
{
	int x, y;
	cout << "Podaj wiersz: ";
	cin >> x;
	cout << "Podaj kolumne: ";
	cin >> y;

	if (BOARD[x][y] == BLANK_SPACE)
	{
		BOARD[x][y] = playerSymbol;
		return HasWon(playerSymbol, x, y);
	}
	else
	{
		cout << "To pole jest zajete" << endl;
		PlayerInput(playerSymbol);
	}
}

bool BotPlayer()
{
	while (true)
	{
		int x = rand() % BOARD_SIZE;
		int y = rand() % BOARD_SIZE;

		if (BOARD[x][y] == BLANK_SPACE)
		{
			BOARD[x][y] = 'O';
			return HasWon('O', x, y);
		}
	}
}

int main()
{
	srand(time(nullptr));

	Initialize();

	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i)
	{
		Render();
		if (i % 2 == 0)
		{
			if (PlayerInput('X'))
			{
				Render();
				cout << "Wygrales, gratulacje!";
				return 0;
			}
		}
		else
		{
			if (BotPlayer())
			{
				Render();
				cout << "Przegrales, wygral BOT!";
				return 0;
			}
		}
	}
	cout << "Remis!" << endl;


	return 0;
}