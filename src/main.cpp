#include "iostream"
#include "windows.h"
#include "gameLogic.h"

int main()
{
    table = new char(9);
    for (int i = 0; i < 10; i++)
    {
        table[i] = '0' + i;
    }
    int gameState = 0;
    StartGame();
}