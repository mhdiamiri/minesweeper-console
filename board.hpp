#include <random>

#ifndef BOARD_HPP
#define BOARD_HPP
class Board
{
private:
    int remaining;
    int mines;
    int size;
    bool **board;
    char **display;
    int status;

protected:
    void setStatus(int);
    void setMines(int);
    void setSize(int);
    void setRemaining(int);
    void alloc();
    void initializeDisplay();
    void placeMines();
    bool isValidPoint(int, int);
    int countAround(int, int);

public:
    Board();
    Board(int, int);
    void action(int, int);
    void printBoard();
    void free();
    void restart();
    int getStatus();
    int getRemaining();
    int getSize();
    int getMines();
};

#endif