#pragma once
#include "iostream"
class Player
{
    public:
    std::string name;
    int score;
};
std::ostream &operator<<(std::ostream &os, Player const &m) { 
    return os << "Nama: " << m.name << std::endl << "Score: " << m.score << std::endl;
}