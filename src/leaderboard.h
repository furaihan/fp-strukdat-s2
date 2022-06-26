#pragma once
#include "iostream"
#include "player.h"
#include "../include/myLinkedList.h"
#include "../include/VariadicTable.h"

MyLinkedList<player> players;

void DrawLeaderboard()
{
    VariadicTable<int, std::string, int> leaderboard({"No.", "Player Name", "Score"});
}
void SortScore()
{
    
}
void SearchScore()
{

}