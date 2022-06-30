#include "iostream"
#include "windows.h"
#include "gameLogic.h"
#include "leaderboard.h"

int main()
{
    PopulatePlayer();
    table = new char(9);
    for (int i = 0; i < 10; i++)
    {
        *(table + i) = '0' + i;
    }
    int gameState = 0;
    StartGame();
}