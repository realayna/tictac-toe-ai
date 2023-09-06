#include "tictactoe.h"
#include <iostream>
#include <vector>
#include <climits>

void displayBoard(const std::vector<std::vector<char>> &board)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            std::cout << board[i][j];
            if (j < BOARD_SIZE - 1)
                std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < BOARD_SIZE - 1)
        {
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}

bool isBoardFull(const std::vector<std::vector<char>> &board)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (board[i][j] == EMPTY_CELL)
            {
                return false;
            }
        }
    }
    return true;
}

bool isWinner(const std::vector<std::vector<char>> &board, char player)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true; // Diagonal (\) win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true; // Diagonal (/) win
    }
    return false;
}

int evaluateBoard(const std::vector<std::vector<char>> &board)
{
    if (isWinner(board, PLAYER_X))
    {
        return 10;
    }
    else if (isWinner(board, PLAYER_O))
    {
        return -10;
    }
    else
    {
        return 0;
    }
}
int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizing)
{
    
}