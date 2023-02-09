#include "minegame.hpp"

short chooseLevel()
{
    short level = 0;
    while (level > 4 || level < 1)
    {
        cout << "\33[2J\33[1;1H";
        cout << "\t\tMineweeper" << endl
             << endl;
        cout << "\t\t1. Beginner" << endl;
        cout << "\t\t2. Intermediate" << endl;
        cout << "\t\t3. Advanced" << endl;
        cout << "\t\t4. Exit Game" << endl;
        cout << endl;
        cout << "\t\tEnter level:";
        cin >> level;
    }
    return level;
}

int main()
{
    while (true)
    {
        short level = chooseLevel();
        if (level == 4)
            break;
        MineGame game = MineGame(level);
        game.play();
    }
    return 0;
}