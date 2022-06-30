#pragma once
#include "iostream"
#include "player.h"
#include "../include/queue.h"
#include "../include/myLinkedList.h"
#include "../include/Helpers.h"
#include "node.h"
#include "ctime"

Queue<Player> players;

void DrawLeaderboard()
{
    Node<Player> *temp = players.Head();
    while (temp->next != NULL)
    {
        
        temp = temp->next;
    }
}
void SortScore()
{
    
}
void SearchScore()
{

}
void PopulatePlayer()
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        Player *player = new Player;
        player->name = "COM " + IntToString(i + 1);
        player->score = ((rand() % 4) * 20) + 100;
        players.Enqueue(*player);
    }
}