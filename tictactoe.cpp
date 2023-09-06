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
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE;j++)
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
    for (int i = 0; i < BOARD_SIZE; i++)
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
int minimax(std::vector<std::vector<char>> &board, int depth, bool isMaximizing)
{
    int score = evaluateBoard(board);

    if (score == 10 || score == -10)
    {
        return score;
    }

    if (isBoardFull(board))
    {
        return 0;
    }
    if (isMaximizing)
    {
        int maxEval = INT_MIN;
        for (int i = 0; i < BOARD_SIZE; ++i)
        {
            for (int j = 0; j < BOARD_SIZE; ++j)
            {
                if (board[i][j] == EMPTY_CELL)
                {
                    board[i][j] = PLAYER_X;
                    int eval = minimax(board, depth + 1, false);
                    board[i][j] = EMPTY_CELL;
                    maxEval = std::max(maxEval, eval);
                }
            }
        }
        return maxEval;
    }
    else
    {
        int minEval = INT_MAX;
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (board[i][j] == EMPTY_CELL)
                {
                    board[i][j] = PLAYER_O;
                    int eval = minimax(board, depth + 1, true);
                    board[i][j] = EMPTY_CELL;
                    minEval = std::min(minEval, eval);
                }
            }
        }
        return minEval;
    }
}

Move findBestMove(std::vector<std::vector<char>> &board)
{
    int bestVal = INT_MIN;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY_CELL)
            {
                board[i][j] = PLAYER_X;
                int moveVal = minimax(board, 0, false);
                board[i][j] = EMPTY_CELL;
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}
