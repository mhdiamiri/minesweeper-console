#include <iostream>
#include <iomanip>
#include "minegame.hpp"

using namespace std;

MineGame::MineGame()
{
    MineGame(0);
}

MineGame::MineGame(short l) : Game()
{
    level = l;
    switch (level)
    {
    case BEGINNER:
        board = Board(BEGINNER_MINES, BEGINNER_SIZE);
        break;
    case INTERMEDIATE:
        board = Board(INTERMEDIATE_MINES, INTERMEDIATE_SIZE);
        break;
    case ADVANCED:
        board = Board(ADVANCED_MINES, ADVANCED_SIZE);
        break;
    }
}

MineGame::~MineGame()
{
    board.free();
}

void MineGame::play()
{
    Game::play();
    while (isRunning())
    {
        board.printBoard();
        cout << "Remaining Blocks: " << board.getRemaining() << endl;
        cout << "Enter i and j (Enter -1 to exit): ";
        int ii, jj;
        cin >> ii;
        if (ii == -1)
        {
            pause();
            return;
        }
        cin >> jj;
        board.action(ii, jj);
        if (board.getStatus() != 0)
            pause();
    }
    if (board.getStatus() == 1)
    {
        board.printBoard();
        cout << "YOU WON!" << endl;
        cout << "Press Enter to exit.";
        cin.clear();
        cin.get();
        cin.get();
        return;
    }
    else
    {
        board.printBoard();
        cout << "GAME OVER." << endl;
        cout << "Do you want to restart the Game? (Same Board) [y/n]";
        char ans;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
            restart();
        return;
    }
}

void MineGame::restart()
{
    board.restart();
    play();
}

void MineGame::setLevel(short l)
{
    level = l;
}

short MineGame::getLevel()
{
    return level;
}
