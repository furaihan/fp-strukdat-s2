#pragma once
#include "iostream"
#include "player.h"
#include "leaderboard.h"
/*
    Chrono library
chrono adalah nama header, tetapi juga sub-namespace: Semua elemen dalam header ini (kecuali untuk spesialisasi common_type) 
tidak didefinisikan secara langsung di bawah namespace std (seperti kebanyakan library standar) tetapi di bawah namespace std::chrono
Elemen-elemen dalam header ini berhubungan dengan waktu. Hal ini dilakukan terutama dengan menggunakan tiga konsep:

Durasi
Mereka mengukur rentang waktu, seperti satu menit, dua jam, atau sepuluh milidetik.
Di library ini, mereka diwakili dengan objek dari templat kelas durasi, 
yang menggabungkan representasi hitungan dan presisi periode 
(misalnya, sepuluh milidetik memiliki sepuluh sebagai representasi hitungan dan milidetik sebagai presisi periode).

Titik waktu
Referensi ke titik waktu tertentu, seperti ulang tahun seseorang, 
fajar hari ini, atau saat kereta berikutnya lewat.
Di library ini, objek dari templat kelas time_point mengekspresikannya 
dengan menggunakan durasi relatif terhadap epoch (yang merupakan titik tetap 
dalam waktu yang umum untuk semua objek time_point menggunakan jam yang sama).

jam
framework yang menghubungkan titik waktu dengan waktu fisik nyata.
Library ini menyediakan setidaknya tiga jam yang menyediakan sarana untuk mengekspresikan 
waktu saat ini sebagai time_points: system_clock, steady_clock, dan high_resolution_clock.

*/
#include "chrono"
#include "thread"                                                       /*Library yang berisi fungsi fungsi thread*/

char *table;                                                            /*Variabel untuk menyimpan nilai tabel tictactoe*/
Player player1;                                                         /*Variabel struct player untuk player 1*/
Player player2;                                                         /*Variabel struct player untuk player 2*/
Player *winner;                                                         /*Variabel untuk menyimpan player yang memenangkan permainan*/
std::string nameTurn = "";                                              /*Variabel untuk menyimpan nama dari pemain pada ronde saat ini*/
const std::string cellLine = "     |     |     ";                       /*Variable konstan untuk keperluan display tabel tictactoe*/
const std::string cellLineWithDash = "_____|_____|_____";               /*Variable konstan untuk keperluan display tabel tictactoe*/
int turn = 1;                                                           /*Variabel untuk logika penentuan giliran bermain*/
int choice;                                                             /*Variabel untuk menyimpan pilihan cell player*/
int gameStatus;                                                         /*Variabel untuk logika penentuan apakah game menang / draw / masih bisa lanjut*/
char mark;                                                              /*Variabel untuk mengganti value dari tabel. Rentang nilai: 'X' dan 'O'*/
bool gameStarted = false;                                               /*Variabel logika apakah game sudah ada pemenangnya*/
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
        //menentukan nama player yang bermain
        nameTurn = (turn % 2) ? player1.name : player2.name;
        turn = (turn % 2) ? 1 : 2;
        std::cout << nameTurn << ", enter a number:  ";
        std::cin >> choice;
        //Menentukan tanda, apabila player 1 maka 'X' dan player 2 maka 'O'
        mark = (turn == 1) ? 'X' : 'O';

        //Variabel untuk menentukan apakah pilihan nomor tabel yang dimasukkan valid
        int setRet = SetCell(choice, mark);
        if(setRet == -1) {
            //jika tidak valid maka masuk ke block ini
            std::cout << "Invalid move";
            turn--;
            std::cin.ignore();
            std::cin.get();
        }
        gameStatus = WinnerCheck();
        turn++;
    } while(gameStatus == -1);
    DrawBoard();

    if(gameStatus == 1) {
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

    std::cout << player1.name << " (X) - "<< player2.name <<" (O) " << std::endl << std::endl;
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
//fungsi untuk menampilkan fake loading screeen
void DrawLoading()
{
    system("cls");
    std::string files[8] = 
    {
        "standard c++ library", "main.cpp", "menu.h", "player.h", "leaderboard.h", "node.h", "queue.h", "helpers.h"
    };
    /* dynamic array untuk menyimpan bar yang akan ditampilkan pada loading screen
    array ini berisikan char '.' yang nanti akan diubah ke '#' seiring berjalannya loading */
    char *loadingBar = new char[25];
    //perulangan untuk mengisi array loadingBar
    for (int i = 0; i < 25; i++)
    {
        *(loadingBar + i) = '.';
    }
    //perulangan untuk menampilkan loading hingga 100%
    for (int i = 0; i <= 100; i++)
    {
        std::string file;
        //percabangan untuk menentukan file yang di loading
        if (i < 30) file = files[0];
        else if (i < 40) file = files[1];
        else if (i < 50) file = files[3];
        else if (i < 60) file = files[4];
        else if (i < 70) file = files[5];
        else if (i < 80) file = files[6];
        else if (i == 100) file = "Complete";
        else file = files[7];
        printf("   Loading %s\n[", file.c_str());
        //perulangan untuk menampilkan isi dari array loadingBar
        for (int j = 0; j < 25; j++) printf("%c", *(loadingBar + j));
        printf("] %i%%",i);
        //delay_ms
        std::this_thread::sleep_for(std::chrono::milliseconds((rand() % 95) + 20));
        //mengganti value array dari '.' menjadi '#'
        if (*(loadingBar + (i / 4)) != '#') *(loadingBar + (i / 4)) = '#';
        system("cls");
    }
    delete[] loadingBar;
}
//untuk mereset tictactoe 
void ResetTable()
{
    //perulangan untuk mengatur ulang nilai tabel tictactoe
    for (int i = 0; i < 10; i++)
    {
        *(table + i) = '0' + i;
    }
    turn = 1;
}

/*array multidimensi yang menyimpan posisi grid yang sejajar
baik vertical, horizontal, maupun diagonal
*/
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
//fungsi untuk mengubah nilai pada grid
int SetCell(int choice, char mark)
{
    /*jika posisi grid valid maka akan mengubah angka pada grid dan mengembalikan nilai 1
    valid ditentukan dengan mengecek apakah input yang dimasukkan terdapat pada array table */
    if(table[choice] == '0' + choice) {
        table[choice] = mark;
        return 1;
    } else {
        return -1;
    }
}
bool IsDraw()
{
    int counter2 = 0;   /*Variabel untuk menghitung jumlah X atau O dalam tabel tic tac toe*/
    int counter = 1;    /*Variabel untuk melakukan iterasi taerhadab array table*/
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
//menghitung score
int CalculateScore()
{
    int counter2 = 0;   /*Variabel untuk menghitung jumlah X atau O dalam tabel tic tac toe*/
    int counter = 1;    /*Variabel untuk melakukan iterasi taerhadab array table*/
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
//mencari rank dari pemenang terakhir pada leaderboard
//sequential search
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