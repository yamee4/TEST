#include "Normal.h"
#include"Console.h"
#include <conio.h>
#include "CheckMatch1.h"
void generateElements(char*& temp, int& nRows, int& nCols)
{
	temp = new char[nRows * nCols];
	int index = 0;

	for (int i = 0; i < (nRows * nCols) / 2; i++)
	{
		temp[i] = 'A' + rand() % 26;
	}

	for (int i = (nRows * nCols) / 2; i < nRows * nCols; i++)
	{
		temp[i] = temp[index++];
	}
}

void initializeBoardView(CELL1**& board, int& rowNumbers, int& columeNumbers)
{
	srand(time(NULL));

	//Create a new board
	board = new CELL1 * [rowNumbers];

	for (int i = 0; i < rowNumbers; i++)
	{
		board[i] = new CELL1[columeNumbers];

		for (int j = 0; j < columeNumbers; j++) {
			board[i][j].j = j;
			board[i][j].i = i;
		}
	}

	//Generate elements to the board
	int pos = 0;
	char* temp;

	//Generate characters into a char array
	generateElements(temp, rowNumbers, columeNumbers);

	//Put all the elements into the board
	int flagPos = (rowNumbers * columeNumbers) / 2;
	while (flagPos) {
		int index;
		int cntPair = 2;
		while (cntPair)
		{
			int index = rand() % (rowNumbers * columeNumbers);

			if (board[index / columeNumbers][index % columeNumbers].letter == ' ') {

				board[index / columeNumbers][index % columeNumbers].letter = temp[pos++];
				cntPair--;
			}
		}
		flagPos--;
	}

	delete[]temp;
}

//delete a box when a pair up are made and after finished game
void deleteBoard(CELL1** board, int& rowNumbers, int& columeNumbers)
{
	for (int i = 0; i < rowNumbers; i++)
	{
		for (int j = 0; j < columeNumbers; j++)
		{
			if (board[i][j].isNotEmpty)
				board[i][j].deleteBox();
			//display background (implement later...)
		}
	}
	for (int i = 0; i < rowNumbers; i++)
	{
		delete[]board[i];
	}
	delete[]board;
}

void displayBoard(CELL1** board, int& rowNumbers, int& columeNumbers)
{
	for (int i = 0; i < rowNumbers; i++)
	{
		for (int j = 0; j < columeNumbers; j++)
		{
			board[i][j].drawBox(112);
		}
	}
}

void moveInBoard(CELL1** board, int& BOARDHEIGHT, int& BOARDWIDTH, int& status, int& pairup, position& pos, player& p, position selectedPos[])
{
	int keybind, key;
	keybind = _getch();
	if (keybind && keybind != 224) // Not an arrow key
	{
		if (keybind == ESC_KEY) // An ESC key 
		{ 
			status = 1; // You quit the game, back to main menu
		}

		else if (keybind == ENTER_KEY)
		{
			if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y)
			{
				board[selectedPos[0].y][selectedPos[0].x].drawBox(70);
				Sleep(500);

				board[selectedPos[0].y][selectedPos[0].x].isSelected = false;
				pairup = 2;
				selectedPos[0] = { -1, -1 };
			}

			else
			{
				selectedPos[2 - pairup].x = pos.x;
				selectedPos[2 - pairup].y = pos.y;
				board[pos.y][pos.x].isSelected = true;
				pairup--;
				
				if (pairup == 0)
				{
					if (board[selectedPos[0].y][selectedPos[0].x].letter == board[selectedPos[1].y][selectedPos[1].x].letter) // if this 2 pair are valid
					{
						if (allcheck(board, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x, BOARDHEIGHT, BOARDWIDTH))
						{
							p.point += 20;
							goToXY(40, 0);
							cout << "Point: " << p.point;

							board[selectedPos[0].y][selectedPos[0].x].drawBox(40);
							board[selectedPos[1].y][selectedPos[1].x].drawBox(40);
							Sleep(500);

							board[selectedPos[0].y][selectedPos[0].x].isNotEmpty = false;
							board[selectedPos[0].y][selectedPos[0].x].deleteBox();
							//if (selectedPos[0].x < 4) displayBackground(bg, selectedPos[0].x, selectedPos[0].y); (implement later...)

							board[selectedPos[1].y][selectedPos[1].x].isNotEmpty = false;
							board[selectedPos[1].y][selectedPos[1].x].deleteBox();
							//if (selectedPos[1].x < 4) displayBackground(bg, selectedPos[1].x, selectedPos[1].y);
						}
						else
						{
							board[selectedPos[0].y][selectedPos[0].x].drawBox(70);
							board[selectedPos[1].y][selectedPos[1].x].drawBox(70);
							Sleep(500);
						}
					}

					else
					{
						board[selectedPos[0].y][selectedPos[0].x].drawBox(70);
						board[selectedPos[1].y][selectedPos[1].x].drawBox(70);
						Sleep(500);
					}

					//Return to their original position

					board[selectedPos[0].y][selectedPos[0].x].isSelected = false;
					board[selectedPos[1].y][selectedPos[1].x].isSelected = false;
					pairup = 2;
					selectedPos[0] = { -1, -1 };
					selectedPos[1] = { -1, -1 };

					for (int i = pos.y; i < BOARDHEIGHT; i++) 
					{
						for (int j = pos.x; j < BOARDWIDTH; j++) 
						{
							if (board[i][j].isNotEmpty)
							{
								pos.x = j;
								pos.y = i;
								return;
							}
						}
					}

					for (int i = 0; i <= pos.y; i++) 
					{
						for (int j = 0; j <= pos.x; j++) 
						{
							if (board[i][j].isNotEmpty) 
							{
								pos.x = j;
								pos.y = i;
								return;
							}
						}
					}
				}

			}
		}
	}

	else
	{
		if ((pos.x != selectedPos[0].x || pos.y != selectedPos[0].y) && (pos.x != selectedPos[1].x || pos.y != selectedPos[1].y)) // check if this box is selected
			board[pos.y][pos.x].isSelected = false;

		switch (key=_getch()) 
		{
			case KEY_UP:

			for (int i = pos.x; i < BOARDWIDTH; i++)
			{
				for (int j = pos.y - 1; j >= 0; j--)
				{
					if (board[j][i].isNotEmpty)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x - 1; i >= 0; i--)
			{
				for (int j = pos.y - 1; j >= 0; j--) {
					if (board[j][i].isNotEmpty)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x; i < BOARDWIDTH; i++)
			{
				for (int j = BOARDHEIGHT - 1; j > pos.y; j--)
				{
					if (board[j][i].isNotEmpty)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}
			
			for (int i = pos.x; i >= 0; i--) 
			{
				for (int j = BOARDHEIGHT - 1; j > pos.y; j--) 
				{
					if (board[j][i].isNotEmpty)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			break;

			case KEY_DOWN:
				for (int i = pos.x; i < BOARDWIDTH; i++)
				{
					for (int j = pos.y + 1; j < BOARDHEIGHT; j++)
					{
						if (board[j][i].isNotEmpty)
						{
							pos.x = i;
							pos.y = j;
							return;
						}
					}
				}

				for (int i = pos.x - 1; i >= 0; i--)
				{
					for (int j = pos.y + 1; j < BOARDHEIGHT; j++)
					{
						if (board[j][i].isNotEmpty)
						{
							pos.x = i;
							pos.y = j;
							return;
						}
					}
				}

				for (int i = pos.x; i < BOARDWIDTH; i++)
				{
					for (int j = 0; j < pos.y; j++)
					{
						if (board[j][i].isNotEmpty)
						{
							pos.x = i;
							pos.y = j;
							return;
						}
					}
				}

				for (int i = pos.x - 1; i >= 0; i--)
				{
					for (int j = 0; j < pos.y; j++)
					{
						if (board[j][i].isNotEmpty)
						{
							pos.x = i;
							pos.y = j;
							return;
						}
					}
				}
				break;

			case KEY_LEFT:
				for (int i = pos.y; i >= 0; i--)
				{
					for (int j = pos.x - 1; j >= 0; j--)
					{
						if (board[i][j].isNotEmpty) {
							pos.x = j;
							pos.y = i;
							return;
						}

					}
				}

				for (int i = pos.y + 1; i < BOARDHEIGHT; i++)
				{
					for (int j = pos.x - 1; j >= 0; j--)
					{
						if (board[i][j].isNotEmpty) {
							pos.x = j;
							pos.y = i;
							return;
						}

					}
				}

				for (int i = pos.y; i >= 0; i--)
				{
					for (int j = BOARDWIDTH - 1; j > pos.x; j--)
					{
						if (board[i][j].isNotEmpty) {
							pos.x = j;
							pos.y = i;
							return;
						}
					}
				}

				for (int i = pos.y + 1; i < BOARDHEIGHT; i++)
				{
					for (int j = BOARDWIDTH - 1; j > pos.x; j--)
					{
						if (board[i][j].isNotEmpty) {
							pos.x = j;
							pos.y = i;
							return;
						}
					}

				}
				break;

			case KEY_RIGHT:
				for (int i = pos.y; i >= 0; i--)
				{
					for (int j = pos.x + 1; j < BOARDWIDTH; j++)
					{
						if (board[i][j].isNotEmpty) {
							pos.x = j;
							pos.y = i;
							return;
						}
					}
				}

				for (int i = pos.y + 1; i < BOARDHEIGHT; i++)
				{
					for (int j = pos.x; j < BOARDWIDTH; j++)
					{
						if (board[i][j].isNotEmpty) {
							pos.x = j;
							pos.y = i;
							return;
						}
					}
				}

				for (int i = pos.y + 1; i >= 0; i--)
				{
					for (int j = 0; j < pos.x; j++)
					{
						if (board[i][j].isNotEmpty) {
							pos.x = j;
							pos.y = i;
							return;
						}
					}
				}

				for (int i = pos.y + 1; i < BOARDHEIGHT; i++)
				{
					for (int j = 0; j < pos.x; j++)
					{
						if (board[i][j].isNotEmpty) {
							pos.x = j;
							pos.y = i;
							return;
						}
					}
				}
				break;

			default:
				break;
		}
	}
}

void initNormalMode(player& p)
{
	srand(time(NULL));
	CELL1** BOARD;
	int BOARDWIDTH = 4;
	int BOARDHEIGHT = 4;
	initializeBoardView(BOARD, BOARDHEIGHT, BOARDWIDTH);

	goToXY(45, 0);
	cout << "POINT: " << p.point;
	position SelectedPos[] = { {-1,-1},{-1,-1} };
	int pairup = 2;
	position Cursor = { 0,0 };
	int status = 0; // 0: Currently playing
					// 1: The player has quitted the game

	while (true)
	{
		BOARD[Cursor.y][Cursor.x].isSelected = true;
		displayBoard(BOARD, BOARDHEIGHT, BOARDWIDTH);
		moveInBoard(BOARD, BOARDHEIGHT, BOARDWIDTH, status, pairup, Cursor, p, SelectedPos);

		if (!checkValidPairs(BOARD, BOARDHEIGHT, BOARDWIDTH))
			break;

		else if (status == 1) //Player has quitted the game, back to main menu
			break;
	}

	displayBoard(BOARD, BOARDHEIGHT, BOARDWIDTH);
	deleteBoard(BOARD, BOARDHEIGHT, BOARDWIDTH);
	Sleep(500);
	system("pause");
}