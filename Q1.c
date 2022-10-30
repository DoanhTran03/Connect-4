#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool make_move (char board[6][7], int column, char player) {
assert (column >= 0 && column < 7);
int row = 0;
if (board[row][column] != 'X' && board[row][column] != 'O') {                       //check if row = 0 have XO or not;
    while (board[row][column] != 'X' && board[row][column] != 'O' && row < 6) {     // find position X and O will be put into;
        row++;                                                                         
    }
    row--;
    board[row][column] = player;
return true;
}
return false;
}

void test_make_move (char board[6][7]) {
    // vertical tests
    assert(make_move(board,6,'O'));
    assert(make_move(board,6,'X'));
    assert(make_move(board,6,'X'));
    assert(make_move(board,6,'O'));
    assert(make_move(board,6,'X'));
    assert(make_move(board,6,'X'));
    assert(!make_move(board,6,'X'));        // column is full

    assert(board[5][6] == 'O');
    assert(board[4][6] == 'X');

    //assert(make_move(board,7,'O') == true);         // this will not work since the condition in make_move

    // horizontal tests
    assert(make_move(board,0,'O'));
    assert(make_move(board,1,'X'));
    assert(make_move(board,2,'O'));
    assert(board[5][0] == 'O'); 
    assert(board[5][1] == 'X');
    assert(board[5][2] == 'O');

// WIN TEST
    // vertical test winn;
    assert(make_move(board,0,'O'));
    assert(make_move(board,0,'O'));
    assert(make_move(board,0,'O'));

    // horizontal test win;
    assert(make_move(board,3,'O'));
    assert(make_move(board,4,'O'));
    assert(make_move(board,5,'O'));

    //diagonal test win;
    assert(make_move(board,2,'X'));
    assert(make_move(board,3,'O'));
    assert(make_move(board,3,'X'));
    assert(make_move(board,4,'O'));
    assert(make_move(board,4,'O'));
    assert(make_move(board,4,'X'));

    //back diagonal test win;
    assert(make_move(board,2,'O'));
    assert(make_move(board,1,'X'));
    assert(make_move(board,1,'X'));
    assert(make_move(board,1,'O'));
    assert(make_move(board,2,'O'));
}

void print_board (char board[6][7], int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (board[i][j] == 'O') {
                printf("%c",'O');}
            else if (board[i][j] == 'X') {
                printf("%c",'X');}
            else {
                printf("%c",' ');
            }
        }
    puts("");
    }
}

bool check_win (char board[6][7],char player) {
// check for horizontal
for (int i = 0; i < 6; i ++) {
    for (int way = 0; way < 4; way++) {
        if (board[i][way] == player){
        int count = 0;
        for (int j = way; j < way + 4 ; j++) {
            if (board[i][j] == board[i][way])
            count++;
        }
        if (count == 4) {
            return true;
        }
        }
        }
    }


// check for vertical
for (int i = 0; i < 7; i++) {
    for (int way = 0; way < 3; way++) {
        if (board[way][i] == player) {
        int count = 0;
        for (int j = way; j < way + 4; j++) {
            if (board[j][i] == board[way][i])
            count++;
        }
        if (count == 4)
        return true;
        }
    }
}

//check for diagonal

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
            if (board[i][j] == player && board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3])
            return true;
    }
}
//check for back diagonal

for (int i = 0; i < 3; i++) {
    for (int j = 6; j >= 3; j--){
        if (board[i][j] == player && board[i][j] == board[i+1][j-1] && board[i][j] == board[i+2][j-2] && board[i][j] == board[i+3][j-3])
        return true;
    }
}

return false;
}

void test_check_win (char board[6][7]) {
    assert(check_win(board,'X'));
    assert(check_win(board,'O'));
    // all cases test for check wins is in test_make_move, please refer to the code in the function;
}

int main (void) {
char board[6][7] = {0};
test_make_move(board);
test_check_win(board);

print_board(board,6,7);
puts("All tests passed successfully");
}