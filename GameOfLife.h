#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "Engine.h"

class GameOfLife : public Engine{
private:
    GameOfLife(const GameOfLife& game);
    GameOfLife& operator=(const GameOfLife& game);
protected:
    GameOfLife(int rows, int columns);
    void virtual View() = 0;
    virtual ~GameOfLife() {};
public:
     void Play();
};
#endif // GAMEOFLIFE_G
