#include "iostream"

char *table;
const std::string cellLine = "     |     |     ";
const std::string cellLineWithDash = "_____|_____|_____";
int turn = 1, choice, k;
char mark;
void DrawBoard()
{
    system("cls");
    std::cout << "\n\n\tTic Tac Toe\n\n";

    std::cout << "Player 1 (X) - Player 2 (O)" << std::endl << std::endl;
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
int CheckWin()
{
    for(int i = 1; i < 10; i++) {
        if((i % 3 == 1 && (table[i] == table[i+1] && table[i+1] == table[i+2])) or 
                (i <= 3 && (table[i] == table[i+3] && table[i+3] == table[i+6])) or 
                (i == 1 && (table[1] == table[5] && table[5] == table[9])) or 
                (i == 3 && (table[3] == table[5] && table[5] == table[7]))) {
            return 1;
        }
        if(table[i] == '0' + i) {
            return -1;
        }
    }
    return 0;
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