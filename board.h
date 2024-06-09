#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    char grid[3][3];
public:
    Board();
    bool placeMark(int row, int col, char mark);
    bool isFull();
    char checkWinner();
    void display();
};

#endif // BOARD_H
