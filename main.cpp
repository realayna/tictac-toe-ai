#include <iostream>
#include <vector>
#include <climits>
#include "tictactoe.h"

int main()
{
    std::vector<std::vector<char>> board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, EMPTY_CELL));
    bool playerTurn = true;
    while (true)
    {
        displayBoard(board);
        if (playerTurn)
        {
            int row, col;
            std::cout << "Enter your move (row and column): ";
            std::cin >> row >> col;

            row -= 1;
            col -= 1;
            if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE &&
                board[row][col] == EMPTY_CELL)
            {
                board[row][col] = PLAYER_O;
                playerTurn = false;
            }
            else
            {
                std::cout << "Invalid move. Try again." << std::endl;
                continue;
            }
        }
        else
        {
            Move bestMove = findBestMove(board);
            board[bestMove.row][bestMove.col] = PLAYER_X;
            playerTurn = true;
        }

        if (isWinner(board, PLAYER_X))
        {
            displayBoard(board);
            std::cout << "AI win!" << std::endl;
            break;
        }
        else if (isWinner(board, PLAYER_O))
        {
            displayBoard(board);
            std::cout << "You win!" << std::endl;
            break;
        }
        else if (isBoardFull(board))
        {
            displayBoard(board);
            std::cout << "It's a draw!" << std::endl;
            break;
        }
    }
}
