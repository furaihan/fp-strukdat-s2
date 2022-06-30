#pragma once
#include <iostream>
#include "gameLogic.h"
#include <stdlib.h>
using namespace std;

void StartMenu()
{
    int pil;
    int pil2;
    do
    {
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
            StartGame();
            cout << "Tekan enter untuk kembali ke menu" << endl;
            system("pause");
            continue;
        }
        else if(pil == 2)
        {
            do
            {
                system("cls");
                cout << "Nama Player1 = " << player1.name << endl;
                cout << "Nama Player2 = " << player2.name << endl << endl;
                cout << "Tekan 1 untuk mengganti nama Player1" << endl;
                cout << "Tekan 2 untuk mengganti nama Player2" << endl;
                cout << "Tekan 0 untuk EXIT" << endl;
                cout << "Inputkan pilihan: "; cin >> pil2;
                if(pil2 == 1)
                {
                    cout << "Silahkan masukan nama Player1(Maks 8 karakter): ";
                    cin.ignore(); 
                    getline(cin, player1.name);
                    system("pause");
                } else if (pil2 == 2)
                {   
                    cout << "Silahkan masukan nama Player2(Maks 8 karakter): "; 
                    cin.ignore();
                    getline(cin, player2.name);
                    system("pause");
                } else
                {
                    cout << "Pilihan tidak tersedia!" << endl;
                    system("pause");
                }
                
                
            } while (pil2 != 0);
            
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