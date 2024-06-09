#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <vector>

class Game {
private:
    Board board;
    char currentPlayer;
    std::vector<std::pair<int, int>> moves;
public:
    Game();
    void switchPlayer();
    void play();
    void saveToFile(char winner);
};

#endif // GAME_H
