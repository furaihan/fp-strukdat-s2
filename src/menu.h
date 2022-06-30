#pragma once
#include <iostream>
#include "gameLogic.h"
using namespace std;

int main()
{
    int pil;
    char pil2;
    do
    {
        menu:
        system("cls");
        cout << "=======================" << endl;
        cout << "       MAIN MENU       " << endl;
        cout << "=======================" << endl;
        cout << "1. Play" << endl;
        cout << "2. Registrasi" << endl;
        cout << "3. Leaderboard" << endl;
        cout << "4. Exit" << endl;
        cout << "Inputkan pilihan: "; cin >> pil;
        if(pil == 1)
        {

        }
        else if(pil == 2)
        {

        }
        else if(pil == 3)
        {

        }
        else if(pil == 4)
        {

        }
        else
        {
            cout << "Pilihan yang anda inputkan tidak tersedia!" << endl;
        }
    } while (pil != 4);
    
    return;
}