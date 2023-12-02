/*
 * Tate MacPhail
 * Created - Dec 2, 2023 2:15 AM
 *
 */

#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>

typedef struct Row {
    char* values[9];
} row_t;

typedef struct Column {
    char* values[9];
} column_t;

typedef struct Square {
    char* values[3][3];
} square_t;

typedef struct Board {
    row_t rows[9];
    column_t columns[9];
    square_t squares[3][3];
    char values[9][9];
} board_t;

/*
 * Use terminal input to fill a sudoku board.
 *
 * PARAMS:
 *      board - pointer to the board struct to be filled
 * PRE:
 *      board != NULL
 * POST:
 *      (*board) is filled with data from user
 */
void fillBoardManual(board_t* board);

/*
 * Reads data from a file to fill the passed board.
 *
 * PARAMS:
 *      board - pointer to the board struct to be filled
 *      input - the input file pointer
 *      format - specifier for the format of the input
 *             0: reads character by character
 *             1: TODO: by row
 *             2: TODO: line by line
 * PRE:
 *      board != NULL &&
 *      input != NULL && [input is open for reading] &&
 *          [input is formatted according to readme] && TODO: make/add formats to readme
 *      format = 0, 1, or 2
 * POST:
 *      (*board) is filled with data from file
 */
void fillBoard(board_t* board, FILE* input, int format);

/*
 * Prints the passed board to terminal
 *
 * PARAMS:
 *      board - pointer to filled board struct
 * PRE:
 *      board contains only characters '0' - '9'
 * POST:
 *      (*board) unchanged
 */
void printBoard(board_t* board);

/*
 * Change the indicated position to the passed character.
 *
 * PARAMS:
 *      board - pointer to a board
 *      row - row of position to change
 *      col - column of position to change
 *      val - the new value for the position
 * PRE:
 *      TODO: Implement tracking original board
 *      board != NULL &&
 *      1 <= row <= 9 &&
 *      1 <= col <= 9 &&
 *      '0' <= val < '9'
 * POST:
 *      The indicated position has been changed to the
 *      passed character.
 */
void changePos(board_t* board, int row, int col, char val);

/*
 * Checks that the board results in a win
 *
 * PARAMS:
 *      board - pointer to the board to be checked
 * PRE:
 *      board != NULL && '0' <= board->values[*][*] <= '9'
 * POST:
 *      board is unchanged
 * RETURNS:
 *      1 if the board is a win, 0 ow
 */
int checkForWin(board_t* board);

#endif
