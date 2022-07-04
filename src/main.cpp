#include "iostream"
#include "gameLogic.h"
#include "leaderboard.h"
#include "menu.h"
#include "ctime"

int main()
{
    player1.name = "Player 1";
    player1.score = 0;
    player2.name = "Player 2";
    player2.score = 0;
    srand((unsigned int)time(NULL));
    PopulatePlayer();
    table = new char(9);
    for (int i = 0; i < 10; i++)
    {
        *(table + i) = '0' + i;
    }
    DrawLoading();
    StartMenu();
    delete[] playerArray;
    delete[] table;
    players.Clear();
    std::cout<< "All memory cleared successfully\n";
    system("pause");
}