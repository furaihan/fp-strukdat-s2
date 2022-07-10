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
    /*Inisialisasi generator nomor acak
    Generator nomor pseudo-acak diinisialisasi menggunakan argumen yang diteruskan sebagai seed.

    Untuk setiap nilai seed berbeda yang digunakan dalam panggilan ke srand, 
    generator nomor pseudo-acak dapat diharapkan untuk menghasilkan suksesi hasil yang berbeda dalam panggilan berikutnya ke rand.
    
    Dua inisialisasi berbeda dengan seed yang sama akan menghasilkan
    suksesi hasil yang sama dalam panggilan berikutnya ke rand.
    
    Jika seed disetel ke 1, generator diinisialisasi ulang ke nilai
    awalnya dan menghasilkan nilai yang sama seperti sebelum panggilan ke rand atau srand.
    
    Untuk menghasilkan angka seperti acak, srand biasanya diinisialisasi 
    ke beberapa nilai runtime yang berbeda, seperti nilai yang dikembalikan 
    oleh waktu fungsi (dideklarasikan dalam header <ctime>). 
    Ini cukup khas untuk sebagian besar kebutuhan pengacakan sepele.
    */
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