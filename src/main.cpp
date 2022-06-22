#include "iostream"
#include "../include/VariadicTable.h"
#include "windows.h"
#include "board.h"

int main()
{
    table = new char(9);
    for (int i = 0; i < 10; i++)
    {
        table[i] = '0' + i;
    }
    int gameState = 0;
    do {
        DrawBoard();
        turn = (turn % 2) ? 1 : 2;

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
        k = CheckWin();
        turn++;
    } while(k == -1);
    DrawBoard();

    if(k == 1) {
        std::cout << "==>\aPlayer " << turn << --turn <<" win ";
    } else {
        std::cout << "==>\aGame draw";
    }
}