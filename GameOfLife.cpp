#include "GameOfLife.h"

GameOfLife::GameOfLife(int rows, int columns) :Engine(rows, columns) {}

void GameOfLife::Play() {

	while (true)
    {
		View();
        Analyze();
	}

}
