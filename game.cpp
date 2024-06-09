#include "game.h"
#include <iostream>
#include <fstream>

Game::Game() : currentPlayer('X') {}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void Game::play() {
    int row, col;
    char winner = ' ';
    while (winner == ' ' && !board.isFull()) {
        board.display();
        std::cout << "Player " << currentPlayer << "'s turn. Enter row and column: ";
        std::cin >> row >> col;
        if (board.placeMark(row, col, currentPlayer)) {
            moves.push_back(std::make_pair(row, col));
            winner = board.checkWinner();
            switchPlayer();
        }
        else {
            std::cout << "Invalid move! Try again.\n";
        }
    }
    board.display();
    if (winner == ' ')
        std::cout << "It's a draw!\n";
    else
        std::cout << "Player " << winner << " wins!\n";
    saveToFile(winner);
}

void Game::saveToFile(char winner) {
    std::ofstream file("game_results.txt", std::ios::app);
    if (file.is_open()) {
        file << "Winner: " << winner << "\n";
        file << "Moves:\n";
        for (const auto& move : moves) {
            file << move.first << " " << move.second << "\n";
        }
        file << "-------------------\n";
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing!\n";
    }
}
