#pragma once
#include "iostream"
#include "player.h"

char *table;
int counter = 1;
int counter2 = 0;
Player player1;
Player player2;
const std::string cellLine = "     |     |     ";
const std::string cellLineWithDash = "_____|_____|_____";
int turn = 1, choice, k;
char mark;
void DrawBoard();
int WinnerCheck();
int CheckWin();
int SetCell(int, char);
bool IsDraw();
void StartGame()
{
    do {
        DrawBoard();
        turn = (turn % 2) ? 1 : 2;
        std::cout << counter2 << std::endl;
        std::cout << "Player " << turn << ", enter a number:  ";
        std::cin >> choice;

        mark = (turn == 1) ? 'X' : 'O';

        int setRet = SetCell(choice, mark);
        if(setRet == -1) {
            std::cout << "Invalid move";
            turn--;
            std::cin.ignore();
            std::cin.get();
        }
        k = WinnerCheck();
        turn++;
    } while(k == -1);
    DrawBoard();

    if(k == 1) {
        std::cout << "==>\aPlayer " << --turn <<" win ";
    } else {
        std::cout << "==>\aGame draw";
    }
}
void DrawBoard()
{
    system("cls");
    std::cout << "\n\n\tTic Tac Toe\n\n";

    std::cout << "Player 1 (X) - Player 2 (O) " << k << std::endl << std::endl;
    std::cout << std::endl;

    for(int i = 1; i < 8; i += 3) {
        if(i == 1) {
            std::cout << cellLine << std::endl;
        }
        std::cout << "  " << table[i] << "  |  " << table[i+1] << "  |  " << table[i+2] << std::endl;
        if(i != 7) {
            std::cout << cellLineWithDash << std::endl;
            std::cout << cellLine << std::endl;
        } else {
            std::cout << cellLine << std::endl << std::endl;
        }
    }
}
int winIndexes[8][3] = 
{
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {1,4,7},
    {2,5,8},
    {3,6,9},
    {1,5,9},
    {3,5,7},
};
int WinnerCheck()
{
    for (int i = 0; i < 8; i++)
    {
        if (table[winIndexes[i][0]] == table[winIndexes[i][1]] &&
        table[winIndexes[i][0]] == table[winIndexes[i][2]])
        {
            return 1;
        }
        /*else
        {
            for (int j = 0; j < 3; j++)
            {
                if (table[winIndexes[i][j]] != 'X' && table[winIndexes[i][j]] != 'O')
                {
                    return -1;
                }
            }
        }*/
    }
    if (IsDraw()) return 0;
    return -1;
}
int SetCell(int choice, char mark)
{
    if(table[choice] == '0' + choice) {
        table[choice] = mark;
        return 1;
    } else {
        return -1;
    }
}
bool IsDraw()
{
    counter2 = 0;
    counter = 1;
    while (counter < 10)
    {
        if (table[counter] != 'X' && table[counter] != 'O')
        {
            counter2++;
        }
        counter++;
    }
    return counter2 == 0;
}