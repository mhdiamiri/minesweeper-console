#include <iostream>
#include <iomanip>
#include "board.hpp"
#include "game.hpp"

using namespace std;

#ifndef MINEGAME_HPP
#define MINEGAME_HPP

class MineGame : public Game
{
private:
    Board board;
    short level;

    enum mines
    {
        BEGINNER_MINES = 9,
        INTERMEDIATE_MINES = 40,
        ADVANCED_MINES = 99
    };

    enum sizes
    {
        BEGINNER_SIZE = 9,
        INTERMEDIATE_SIZE = 16,
        ADVANCED_SIZE = 24
    };

    enum levels
    {
        BEGINNER = 1,
        INTERMEDIATE = 2,
        ADVANCED = 3,
    };

public:
    MineGame();
    ~MineGame();
    MineGame(short);
    void play();
    void restart();
    short getLevel();
    void setLevel(short);
};

#endif