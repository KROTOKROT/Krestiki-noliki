#include "board.h"
#include <iostream>

Board::Board() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = ' ';
        }
    }
}

bool Board::placeMark(int row, int col, char mark) {
    if (row < 1 || row > 3 || col < 1 || col > 3 || grid[row - 1][col - 1] != ' ')
        return false;
    grid[row - 1][col - 1] = mark;
    return true;
}

bool Board::isFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == ' ')
                return false;
        }
    }
    return true;
}

char Board::checkWinner() {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
            return grid[i][0];
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
            return grid[0][i];
    }
    // Check diagonals
    if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2])
        return grid[0][0];
    if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0])
        return grid[0][2];
    return ' ';
}

void Board::display() {
    std::cout << "    1   2   3  \n";
    std::cout << "  +---+---+---+\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << "| " << grid[i][j] << " ";
        }
        std::cout << "|\n";
        std::cout << "  +---+---+---+\n";
    }
}
