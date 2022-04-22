#ifndef GAMETXT_H
#define GAMETXT_H

#include "GameOfLife.h"

class GameTxt : public GameOfLife {
private:
    GameTxt(const GameTxt& txt);
    GameTxt& operator=(const GameTxt& txt);
protected:
    virtual void View();
public:
    GameTxt(int rows, int columns);
    virtual ~GameTxt() {}

};
#endif // GAMETXT_H
