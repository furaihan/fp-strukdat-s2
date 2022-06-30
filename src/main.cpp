#include "iostream"
#include "windows.h"
#include "gameLogic.h"
#include "leaderboard.h"
#include "menu.h"

int main()
{
    player1.name = "Player 1";
    player1.score = 0;
    player2.name = "Player 2";
    player2.score = 0;
    PopulatePlayer();
    table = new char(9);
    for (int i = 0; i < 10; i++)
    {
        *(table + i) = '0' + i;
    }
    int gameState = 0;
    StartMenu();
    delete[] playerArray;
    players.Clear();
}