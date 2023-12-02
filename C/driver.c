/*
 * Tate MacPhail
 * Created - Dec 2, 2023 3:20 AM
 *
 */

#include "sudoku.h"
#include <stdlib.h>
#include <assert.h>

void runMenu(int* printToggle, board_t* board);
void processMenuInput(char input, board_t* board, int* printToggle);

int main(int argc, char* argV[]){
    board_t board;
    FILE* input = NULL;
    // construct board
    switch (argc){
        case 1:
            fillBoardManual(&board);
            break;
        case 2:
            input = fopen(argV[1], "r");
            assert(input != NULL);
            fillBoard(&board, input, 0);
            break;
        case 3:
            input = fopen(argV[1], "r");
            assert(input != NULL);
            assert(argV[2][0] == '1' || argV[2][0] == '2');
            fillBoard(&board, input, argV[2][0] - '0');
            break;
        default:
            // TODO: readme instructions
            printf("Invalid arguments, reference readme\n");
            exit(1);
    }
    printBoard(&board);

    // gameplay loop
    int menuToggle = 1;
    while (!checkForWin(&board)){
        runMenu(&menuToggle, &board);
    }
    printf("You Win! Congrats! Here is your solved puzzle:\n");
    printBoard(&board);
}

void runMenu(int* printToggle, board_t* board){
    char input;
    if (*printToggle){
        printf("------------------------------\n"
               "Welcome to sudoku! Choose one:\n"
               "  c. Change a position\n"
               "  p. Print board\n"
               "  m. Print menu\n"
               "  t. Toggle menu reprinting\n"
               // TODO: "  s. Save board to file"
               "  q. Exit Game\n"
               "------------------------------\n");
    }
    input = getchar();
    // clear line
    while (getchar() != '\n');
    processMenuInput(input, board, printToggle);
}

void processMenuInput(char input, board_t* board, int* printToggle){
    int row = 0, col = 0;
    char val = '\0';
    switch (input){
        case 'c': //TODO: validate input or get better system
            printf("Row [1-9]: ");
            row = getchar() - '0';
            while (getchar() != '\n');
            printf("Col [1-9]: ");
            col = getchar() - '0';
            while (getchar() != '\n');
            printf("Value [0-9]: ");
            val = getchar();
            while (getchar() != '\n');
            printf("%c\n", val);
            changePos(board, row, col, val);
            return;
        case 'p':
            printBoard(board);
            return;
        case 'm':
            printf("\n------------------------------\n"
                   "Welcome to sudoku! Choose one:\n"
                   "  c. Change a position\n"
                   "  p. Print board\n"
                   "  m. Print menu\n"
                   "  t. Toggle menu reprinting\n"
                   // TODO: "  s. Save board to file"
                   "  q. Exit Game\n"
                   "------------------------------\n");
            return;
        case 't':
            *printToggle = !(*printToggle);
            return;
        case 'q':
            exit(1);
        default:
            printf("Invalid input.\n");
            return;
    }
}

