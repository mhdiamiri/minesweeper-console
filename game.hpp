#include <iostream>
#include <iomanip>

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
protected:
    bool running;

public:
    Game();
    void play();
    void pause();
    void restart();
    bool isRunning();
};

#endif