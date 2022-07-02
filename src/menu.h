#pragma once
#include <iostream>
#include "gameLogic.h"
#include <stdlib.h>
#include "conio.h"

void StartMenu()
{
    int pil;
    int pil2;
    do
    {
        system("cls");
        std::cout << "=======================" << std::endl;
        std::cout << "       MAIN MENU       " << std::endl;
        std::cout << "=======================" << std::endl;
        std::cout << "1. Play" << std::endl;
        std::cout << "2. Registrasi" << std::endl;
        std::cout << "3. Leaderboard" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Inputkan pilihan: "; std::cin >> pil;
        if(pil == 1)
        {
            StartGame();
            std::cout << "Tekan tombol apapun untuk kembali ke menu" << std::endl;
            getch();
            continue;
        }
        else if(pil == 2)
        {
            do
            {
                system("cls");
                std::cout << "Nama Player1 = " << player1.name << std::endl;
                std::cout << "Nama Player2 = " << player2.name << std::endl << std::endl;
                std::cout << "Tekan 1 untuk mengganti nama Player1" << std::endl;
                std::cout << "Tekan 2 untuk mengganti nama Player2" << std::endl;
                std::cout << "Tekan 0 untuk EXIT" << std::endl;
                std::cout << "Inputkan pilihan: "; std::cin >> pil2;
                std::string temporaryName = "";
                if(pil2 == 1)
                {
                    std::cout << "Silahkan masukan nama Player1(Maks 8 karakter): ";
                    std::cin.ignore(1000, '\n'); 
                    getline(std::cin, temporaryName);
                    if (IsNameValid(temporaryName) && temporaryName.size() <= 8)
                    {
                        player1.name = temporaryName;
                    }
                    else
                    {
                        std::cout << "Nama tidak valid, silahkan ulangi" << std::endl;
                    }
                    std::cout << "Tekan tombol apapun untuk kembali ke menu" << std::endl;
                    getch();
                } 
                else if (pil2 == 2)
                {   
                    std::cout << "Silahkan masukan nama Player2(Maks 8 karakter): "; 
                    std::cin.ignore(1000, '\n'); 
                    getline(std::cin, temporaryName);
                    if (IsNameValid(temporaryName) && temporaryName.size() <= 8)
                    {
                        player2.name = temporaryName;
                    }
                    else
                    {
                        std::cout << "Nama tidak valid, silahkan ulangi" << std::endl;
                    }
                    std::cout << "Tekan tombol apapun untuk kembali ke menu" << std::endl;
                    getch();
                } 
                else if (pil2 == 0)
                {
                } 
                else
                {
                    std::cout << "Pilihan tidak tersedia!" << std::endl;
                    std::cout << "Tekan tombol apapun untuk kembali ke menu" << std::endl;
                    getch();
                }
            } while (pil2 != 0);            
        }
        else if(pil == 3)
        {
            if (!gameStarted)
            {
                std::cout << "Silahkan play game terlebih dahulu untuk melihat leaderboard" << std::endl;
                std::cout << "Tekan tombol apapun untuk kembali ke menu" << std::endl;
                getch();
            }
            else
            {
                system("cls");
                DrawLeaderboard();
                std::cout << "Tekan tombol apapun untuk kembali ke menu" << std::endl;
                getch();
            }
        }
        else if(pil == 4)
        {
        }
        else
        {
            std::cout << "Pilihan yang anda inputkan tidak tersedia!" << std::endl;
            std::cout << "Tekan tombol apapun untuk kembali ke menu" << std::endl;
            getch();
        }
    } while (pil != 4);  
    return;
}