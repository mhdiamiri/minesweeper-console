#include <iomanip>
#include <iostream>
#include "board.hpp"

using namespace std;

Board::Board()
{
}

Board::Board(int m, int s)
{
    setSize(s);
    setMines(m);
    alloc();
    placeMines();
    initializeDisplay();
    setRemaining(size * size);
    setStatus(0);
}

void Board::alloc()
{
    int s = getSize();
    board = new bool *[s];
    for (int i = 0; i < s; i++)
        board[i] = new bool[s];

    display = new char *[s];
    for (int i = 0; i < s; i++)
        display[i] = new char[s];
}

void Board::initializeDisplay()
{
    int s = getSize();
    for (int i = 0; i < s; i++)
    {
        char *tmp = display[i];
        for (int j = 0; j < s; j++)
            tmp[j] = '-';
    }
}

void Board::placeMines()
{
    int n_mines = getMines();
    int s = getSize();
    srand(time(NULL));
    while (n_mines > 0)
    {
        int random = rand() % (s * s);
        int i = random / s;
        int j = random % s;
        if (~board[i][j])
        {
            board[i][j] = true;
            n_mines--;
        }
    }
}

bool Board::isValidPoint(int i, int j)
{
    int s = getSize();
    return (i >= 0) && (i < s) && (j >= 0) && (j < s);
}

int Board::countAround(int i, int j)
{
    const int around[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int num = 0;

    for (int iter = 0; iter < 8; iter++)
    {
        int ii = around[iter][0] + i;
        int jj = around[iter][1] + j;

        if (isValidPoint(ii, jj))
            if (board[ii][jj])
                num++;
    }

    return num;
}

void Board::action(int i, int j)
{
    int m = getMines();
    const int around[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    if (!isValidPoint(i, j))
        return;

    if (board[i][j])
    {
        display[i][j] = '*';
        setStatus(-1);
        return;
    }

    if (display[i][j] != '-')
        return;

    int num = countAround(i, j);

    if (num == 0)
    {
        display[i][j] = '0';
        setRemaining(getRemaining() - 1);
        if (getRemaining() == m)
        {
            setStatus(1);
            return;
        }
        for (int iter = 0; iter < 8; iter++)
        {
            int ii = around[iter][0] + i;
            int jj = around[iter][1] + j;
            action(ii, jj);
        }
        return;
    }
    display[i][j] = '0' + num;
    setRemaining(getRemaining() - 1);
    if (getRemaining() == m)
        setStatus(1);
    return;
}

void Board::printBoard()
{
    int m = getMines();
    int s = getSize();
    cout << "\33[2J\33[1;1H";
    cout << "Mines: " << m << endl;

    cout << setw(11) << " ";
    for (int i = 0; i < s; i++)
        cout << setw(2) << i;

    cout << endl
         << endl;

    for (int i = 0; i < s; i++)
    {
        cout << setw(10);
        cout << i << "  ";
        for (int j = 0; j < s; j++)
            cout << display[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void Board::free()
{
    int s = getSize();
    if (this->board != NULL)
    {
        for (int i = 0; i < s; i++)
            delete[] this->board[i];

        delete[] this->board;
    }

    if (this->display != NULL)
    {
        for (int i = 0; i < s; i++)
            delete[] this->display[i];

        delete[] this->display;
    }
}

void Board::restart()
{
    int s = getSize();
    initializeDisplay();
    setRemaining(s * s);
    setStatus(0);
}

int Board::getStatus()
{
    return this->status;
}

int Board::getRemaining()
{
    return this->remaining;
}

void Board::setStatus(int value)
{
    this->status = value;
}
void Board::setMines(int value)
{
    this->mines = value;
}
void Board::setSize(int value)
{
    this->size = value;
}
void Board::setRemaining(int value)
{
    this->remaining = value;
}
int Board::getSize()
{
    return this->size;
}
int Board::getMines()
{
    return this->mines;
}