/*
 * Tate MacPhail
 * Created - Dec 2, 2023 2:36 AM
 *
 */

#include "sudoku.h"
#include "stdlib.h"

void fillBoardManual(board_t* board){
    char input;
    printf("Values: 1 - 9, 0 for blank space\n");
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            printf("Enter value for (%d,%d):", row+1, col+1);
            input = getchar();
            // validate
            while (input < '0' || input > '9'){
                printf("Values: 1 - 9, 0 for blank space\n");
                input = getchar();
            }
            // assign relevant values
            board->values[row][col] = input;
            board->rows[row].values[col] = &(board->values[row][col]);
            board->columns[col].values[row] = &(board->values[row][col]);
            board->squares[row/3][col/3].values[row%3][col%3] =
                                                &(board->values[row][col]);
            // clear line
            while (getchar() != '\n');
        }
    }
}

void fillBoard(board_t* board, FILE* input, int format){
    int row, col;
    switch(format){
        case 0:
            for(row = 0; row < 9; row++){
                for (col = 0; col < 9; col++){
                    board->values[row][col] = fgetc(input);
                }
            }
            break;
        case 1:
            for (row = 0; row < 9; row++){
                col = 0;
                do {
                    board->values[row][col] = fgetc(input);
                } while (col++ < 9 && board->values[row][col] != '\n');
                // fill rest of row with zeros
                while (col < 9){
                    board->values[row][col] = '0';
                    col++;
                }
            }
            break;
        default:
            printf("Invalid format specified for fillBoard\n");
            exit(1);
    }
    // assign memory addresses with separate nested loop for readability
    for (row = 0; row < 9; row++){
        for (col = 0; col < 9; col++){
            board->rows[row].values[col] = &(board->values[row][col]);
            board->columns[col].values[row] = &(board->values[row][col]);
            board->squares[row/3][col/3].values[row%3][col%3] =
                    &(board->values[row][col]);
        }
    }
}

void printBoard(board_t* board){
    for (int row = 0; row < 9; row++){
        if (row%3 == 0 && row)
            printf("\n");
        for (int col = 0; col < 9; col++){
            if (col%3 == 0 && col) {
                printf("  ");
            }
            if (board->values[row][col] != '0')
                printf("%c ", board->values[row][col]);
            else
                printf("* ");
        }
        printf("\n");
    }
}

void changePos(board_t* board, int row, int col, char val){
    board->values[row-1][col-1] = val;
}

int checkForWin(board_t* board){
    for (int rowNcol = 0; rowNcol < 9; rowNcol++){
        for (int i = 0; i < 9; i++){
            // check for blanks
            if (board->values[rowNcol][i] == '0' || board->values[i][rowNcol] == '0')
                return 0;
            // check for repeats
            for (int n = i + 1; n < 9; n++){
                if (board->values[rowNcol][i] == board->values[rowNcol][n] ||
                        board->values[i][rowNcol] == board->values[n][rowNcol])
                    return 0;
            }
        }
    }
    return 1;
}