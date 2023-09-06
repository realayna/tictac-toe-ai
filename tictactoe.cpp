#include "tictactoe.h"
#include <iostream>
#include <vector>
#include <climits>

void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j];
            if (j < BOARD_SIZE - 1)
                std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < BOARD_SIZE - 1) {
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}
