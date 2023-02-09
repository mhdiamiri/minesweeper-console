#include "game.hpp"

Game::Game()
{
    pause();
}

void Game::play()
{
    running = true;
}

void Game::restart()
{
    play();
}

bool Game::isRunning()
{
    return running;
}

void Game::pause()
{
    running = false;
}