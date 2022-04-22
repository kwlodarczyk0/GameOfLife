#include <iostream>
#include <windows.h>
#include "GameTxt.h"

GameTxt::GameTxt(int rows, int columns) : GameOfLife(rows, columns) {}

void GameTxt::View() {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j]==1)
                std::cout << "X";
            else
                std::cout << ".";
        }
       std::cout << std::endl;
    }

    Sleep(1000);
    system("cls");
}
