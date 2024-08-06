#include <iostream>
using namespace std;

char square[10] = { '0','1','2','3','4','5','6','7','8','9' };

//function to check win
int checkWin() {
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' &&
        square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

//function draw table
void drawBoard() {
    system("cls");
    cout << "\n\n\tTIC TAC TOE GAME\n\n";
    cout << "Player 1(X)\t Player 2(O)\n\n" << endl << endl;
    cout << endl;
    //board
    cout << "     |     |      " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |    " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |    " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |    " << endl;
}

//function to get the move from each player
void getMove(int player, char mark) {
    int choice;
    cout << "Player " << player << ", enter your move:";
    cin >> choice;
    
    if (square[choice] != 'X' && square[choice] != 'O')
        square[choice] = mark;
    else {
        cout << "CASILLERO YA OCUPADO";
        getMove(player,mark);
    }
}

int main()
{
    int player = 1, i, choice;
    char mark;

    do  {
        drawBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1)? 'X' : 'O';
        
        getMove(player, mark);
        
        i = checkWin();
        player++;
    
    } while (i == -1);
    
    drawBoard();
    if (i == 1)
        cout << "\aCONGRATULATIONS!" << " Player " << --player << " wins!\n\n";
    else if (i == 0)
        cout << "DRAW\n\n";
    
    return 0;
}


