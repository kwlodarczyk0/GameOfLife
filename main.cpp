//=====================================
//Autor: Krystian Wlodarczyk
//              Game of life
//====================================

#include "GameTxt.h"

int main()
{
    GameTxt *game =new GameTxt(10,10);
    game->Play();
    delete game;

    return 0;
}
