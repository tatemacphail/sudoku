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
    switch(format){
        case 0:
            for(int row = 0; row < 9; row++){
                for (int col = 0; col < 9; col++){
                    board->values[row][col] = fgetc(input);
                    board->rows[row].values[col] = &(board->values[row][col]);
                    board->columns[col].values[row] = &(board->values[row][col]);
                    board->squares[row/3][col/3].values[row%3][col%3] =
                            &(board->values[row][col]);
                }
            }
            return;
        case 1: // TODO
        case 2: // TODO
        default:
            printf("Invalid format specified for fillBoard\n");
            exit(1);
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