#pragma once
#include "iostream"
#include "gameLogic.h"
#include "player.h"
#include "../include/queue.h"
#include "../include/Helpers.h"
#include "../include/node.h"
#include "ctime"

Queue players;
Player *playerArray;

void SortScore();
void SearchPlayer();
void PopulatePlayer();
void DrawLeaderboard()
{
    SortScore();
    std::cout << "=================================" << std::endl;
    std::cout << "|| Rank ||     Nama   || Score ||" << std::endl;
    std::cout << "=================================" << std::endl;
    
    for(int i=0; i<10; i++)
    {
        int no = i+1;
        const char *nama = playerArray[i].name.c_str();
        int score = (playerArray + i)->score;
        printf("|| %-4i || %-10s || %-5i ||\n", no, nama, score);
        //std::cout << i+1 << "\t" << (playerArray + i)->name << "\t\t" << (playerArray + i)->score << std::endl;
    }
    std::cout << "=================================" << std::endl;
    SearchPlayer();
}
void SortScore()
{
    Node *temp = players.Head();
    int o = 0;
    while (temp != NULL)
    {
        Player dataTemp = temp->data;
        (playerArray + o)->name = dataTemp.name;
        (playerArray + o)->score = dataTemp.score;
        temp = temp->next;
        o++;
    }
    int i, j;
    Player playerKey;
    for (i = 1; i < players.Count(); i++)
    {
        playerKey = playerArray[i];
        j = i - 1;
        while (j >= 0 && playerArray[j].score < playerKey.score)
        {
            playerArray[j + 1] = playerArray[j];
            j = j - 1;
        }
        playerArray[j + 1] = playerKey;
    }
}
void PopulatePlayer()
{
    for (int i = 0; i < 10; i++)
    {
        Player player;
        player.name = "COM " + IntToString(i + 1);
        player.score = ((rand() % 4) * 20) + 100;
        players.Enqueue(player);
    }
    playerArray = new Player[50];
}