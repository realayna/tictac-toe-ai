#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>


const int BOARD_SIZE = 3;
const char EMPTY_CELL = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

struct Move{
    int row; int col;

};

void displayBoard(const std::vector<std::vector<char>>& board);
bool isBoardFull(const std::vector<std::vector<char>>& board);
bool isWinner(const std::vector<std::vector<char>>& board, char player);
int evaluateBoard(const std::vector<std::vector<char>>& board);
int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizing);
Move findBestMove(std::vector<std::vector<char>>& board);

#endif // TICTACTOE_H

