#include"struct.h"
#include"Console.h"
#include<conio.h>
#include<fstream>


//Main menu of the game
int Menu() 
{
    int keybind, key, curChoice = 0;
    int choice[4] = { 0,0,0,0 };
    goToXY(50, 3);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << ".______    __   __  ___      ___       ______  __    __   __    __ ";
    goToXY(50, 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "|   _  \\  |  | |  |/  /     /   \\     /      ||  |  |  | |  |  |  |";
    goToXY(50, 5);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "|  |_)  | |  | |  '  /     /  ^  \\   |  ,----'|  |__|  | |  |  |  |";
    goToXY(50, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "|   ___/  |  | |    <     /  /_\\  \\  |  |     |   __   | |  |  |  |";
    goToXY(50, 7);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "|  |      |  | |  .  \\   /  _____  \\ |  `----.|  |  |  | |  `--'  |";
    goToXY(50, 8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "| _|      |__| |__|\\__\\ /__/     \\__\\ \\______||__|  |__|  \\______/";
    while (true)
    {
        choice[curChoice] = 1;
        if (choice[0])
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);
            for (int i = 0; i < 4; i++)
            {
                goToXY(59, 11 + i);
                cout << "         ";
            }
            goToXY(63, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110+3);
            cout << "NORMAL";
  
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int i = 0; i < 4; i++)
            {
                goToXY(59, 11 + i);
                cout << "         ";
            }
            goToXY(63, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "NORMAL";
        }
        
        if (choice[1])
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
            for (int i = 0; i < 4; i++)
            {
                goToXY(59, 14 + i);
                cout << "         ";
            }
            goToXY(63, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 3);
            cout << "DIFFICULT";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int i = 0; i < 4; i++)
            {
                goToXY(59, 14 + i);
                cout << "         ";
            }
            goToXY(63, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "DIFFICULT";
        }

        if (choice[2])
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
            for (int i = 0; i < 4; i++)
            {
                goToXY(59, 17 + i);
                cout << "         ";
            }
            goToXY(63, 18);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 3);
            cout << "LEADERBOARD";
        }

        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int i = 0; i < 4; i++)
            {
                goToXY(59, 17 + i);
                cout << "         ";
            }
            goToXY(63, 18);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "LEADERBOARD";
        }

        if (choice[3])
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 115);
            for (int i = 0; i < 4; i++)
            {
                goToXY(59, 21 + i);
                cout << "         ";
            }
            goToXY(63, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 115 + 4);
            cout << "EXIT";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int i = 0; i < 4; i++)
            {
                goToXY(59, 21 + i);
                cout << "         ";
            }
            goToXY(63, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "EXIT";
        }

        if (keybind = _getch())
        {
            if (keybind != 224)
            {
                if (keybind == ENTER_KEY)
                {
                    system("cls");
                    return curChoice;
                }
            }

            else
            {
                switch (key = _getch())
                {
                    case KEY_UP:
                        choice[curChoice] = 0;
                        if (curChoice > 0)
                            curChoice--;
                        else
                            curChoice = 3;
                        break;
                    case KEY_DOWN:
                        choice[curChoice] = 0;
                        if (curChoice < 3)
                            curChoice++;
                        else
                            curChoice = 0;
                        break;
                    default:
                        break;
                }
            }
        }
    }

}


void displayBackground(char bg[][41], int x, int y)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            goToXY((x + 1) * 10 + j, (y + 1) * 4 + i);
            cout << bg[y * 4 + i][x * 10 + j];
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}

void resultScreen(int& status)
{
    if (status == 1) {

        goToXY(50, 10);
        cout << " __   __  _______  __   __    ___      _______  _______  _______ ";
        goToXY(50, 11);
        cout << "|  | |  ||       ||  | |  |  |   |    |       ||       ||       |";
        goToXY(50, 12);
        cout << "|  |_|  ||   _   ||  | |  |  |   |    |   _   ||  _____||    ___|";
        goToXY(50, 13);
        cout << "|       ||  | |  ||  |_|  |  |   |    |  | |  || |_____ |   |___ ";
        goToXY(50, 14);
        cout << "|_     _||  |_|  ||       |  |   |___ |  |_|  ||_____  ||    ___|";
        goToXY(50, 15);
        cout << "  |   |  |       ||       |  |       ||       | _____| ||   |___ ";
        goToXY(50, 16);
        cout << "  |___|  |_______||_______|  |_______||_______||_______||_______|";
    }
    else
    {
        goToXY(50, 10);
        cout << " __   __  _______  __   __    _     _  ___   __    _ ";
        goToXY(50, 11);
        cout << "|  | |  ||       ||  | |  |  | | _ | ||   | |  |  | |";
        goToXY(50, 12);
        cout << "|  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| |";
        goToXY(50, 13);
        cout << "|       ||  | |  ||  |_|  |  |       ||   | |       | ";
        goToXY(50, 14);
        cout << "|_     _||  |_|  ||       |  |       ||   | |  _    |";
        goToXY(50, 15);
        cout << "  |   |  |       ||       |  |   _   ||   | | | |   | ";
        goToXY(50, 16);
        cout << "  |___|  |_______||_______|  |__| |__||___| |_|  |__|";
    }



}