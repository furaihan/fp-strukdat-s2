#pragma once
#include "iostream"
#include "player.h"
#include "leaderboard.h"
#include "chrono"
#include "thread"
#include "windows.h"

char *table;
Player player1;
Player player2;
Player *winner;
std::string nameTurn = "";
const std::string cellLine = "     |     |     ";
const std::string cellLineWithDash = "_____|_____|_____";
int turn = 1, choice, k;
char mark;
bool gameStarted = false;
void DrawBoard();
int WinnerCheck();
int CheckWin();
int SetCell(int, char);
bool IsDraw();
int CalculateScore();
void DrawLoading();
void ResetTable();
void StartGame()
{
    do {
        DrawBoard();
        nameTurn = (turn % 2) ? player1.name : player2.name;
        turn = (turn % 2) ? 1 : 2;
        std::cout << nameTurn << ", enter a number:  ";
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
        std::cout << nameTurn <<" win \n";
        winner = new Player;
        winner->name = nameTurn;
        winner->score = CalculateScore();
        std::cout << nameTurn << " score is " << winner->score << std::endl;
        players.Enqueue(*winner);
        gameStarted = true;
    } else {
        std::cout << "==>\aGame draw\n";
    }
    ResetTable();
}
void DrawBoard()
{
    system("cls");
    std::cout << "\n\n\tTic Tac Toe\n\n";

    std::cout << player1.name << " (X) - "<< player2.name <<" (O) " << k << std::endl << std::endl;
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
void DrawLoading()
{
    system("cls");
    std::string files[8] = 
    {
        "standard c++ library", "main.cpp", "menu.h", "player.h", "leaderboard.h", "node.h", "queue.h", "helpers.h"
    };
    char *loadingBar = new char[25];
    for (int i = 0; i < 25; i++)
    {
        *(loadingBar + i) = '.';
    }
    for (int i = 0; i <= 100; i++)
    {
        std::string file;
        if (i < 30) file = files[0];
        else if (i < 40) file = files[1];
        else if (i < 50) file = files[3];
        else if (i < 60) file = files[4];
        else if (i < 70) file = files[5];
        else if (i < 80) file = files[6];
        else if (i == 100) file = "Complete";
        else file = files[7];
        printf("   Loading %s\n[", file.c_str());
        for (int j = 0; j < 25; j++) printf("%c", *(loadingBar + j));
        printf("] %i%%",i);
        std::this_thread::sleep_for(std::chrono::milliseconds((rand() % 95) + 20));
        //Sleep((rand() % 95) + 20);
        if (*(loadingBar + (i / 4)) != '#') *(loadingBar + (i / 4)) = '#';
        system("cls");
    }
    delete[] loadingBar;
}
void ResetTable()
{
    for (int i = 0; i < 10; i++)
    {
        *(table + i) = '0' + i;
    }
    turn = 1;
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
    int counter2 = 0;
    int counter = 1;
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
int CalculateScore()
{
    int counter2 = 0;
    int counter = 1;
    while (counter < 10)
    {
        if (table[counter] != 'X' && table[counter] != 'O')
        {
            counter2++;
        }
        counter++;
    }
    return counter2 * 20 + 100;
}
void SearchPlayer()
{
    for (int i = 0; i < players.Count(); i++)
    {
        if (playerArray[i].name == winner->name)
        {
            std::cout << "Pemanang terakhir ada di ranking " << i + 1 << std::endl;
            return;
        }
    }
    std::cout << "Pemenang terakhir tidak masuk ke leaderboard" << std::endl;
}