#include <fstream>
#include "Engine.h"

Engine::Engine(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    arr = new bool* [rows];
    tmp = new bool* [rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new bool[columns];
        tmp[i] = new bool[columns];
    }
    Init();
}

Engine::~Engine(){
    if(arr){
        for(int i=0;i<columns;i++)
            delete [] arr[i];
        delete [] arr;
    }
    if(tmp){
        for(int i=0;i<columns;i++)
            delete [] tmp[i];
        delete [] tmp;
    }

}

void Engine::Init() {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] = 0;
            tmp[i][j] = 0;
        }
    }

    std::ifstream file("config.ini");
    while(!file.eof())
    {
        int x;
        int y;
        file>>x;
        file>>y;
        arr[x][y] = 1;

    }
    file.close();
}

void Engine::Analyze() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
        {
            int  n = checkNeighbors(i, j);
            if (arr[i][j]==0)
            {
                if (n == 3)
                    tmp[i][j] = 1;
                else
                    tmp[i][j]=0;
            }
            else {
                if (n != 2 && n!=3)
                    tmp[i][j] = 0;
                else{
                    tmp[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++){
            bool c = arr[i][j];
            arr[i][j] = tmp[i][j];
            tmp[i][j] = c;
        }

}

int Engine::checkNeighbors(int x, int y) {
   int counter = 0;

    if(x==0 && y==0){
        if(arr[x+1][y]) counter++;
        if(arr[x][y+1]) counter++;
        if(arr[x+1][y+1]) counter++;

    }
    else if(x==0 && y==columns-1){
        if(arr[x][y-1]) counter++;
        if(arr[x+1][y]) counter++;
        if(arr[x+1][y-1]) counter++;
    }
    else if(x== rows-1 && y ==0){
        if(arr[x-1][y]) counter++;
        if(arr[x-1][y+1]) counter++;
        if(arr[x][y+1]) counter++;
    }
    else if(x== rows-1 && y == columns-1){
        if(arr[x][y-1]) counter++;
        if(arr[x-1][y-1]) counter++;
        if(arr[x-1][y]) counter++;
    }
    else if((x!=0 && x!= rows-1) && y==0){
        if(arr[x-1][y]) counter++;
        if(arr[x+1][y]) counter++;
        if(arr[x][y+1]) counter++;
        if(arr[x-1][y+1]) counter++;
        if(arr[x+1][y+1]) counter++;
    }
    else if(x==0 && (y!=0 && y!=columns-1))
    {
         if(arr[x][y-1]) counter++;
         if(arr[x][y+1]) counter++;
         if(arr[x+1][y]) counter++;
         if(arr[x+1][y-1]) counter++;
         if(arr[x+1][y+1]) counter++;
    }
    else if(y==columns-1 && (x!=0&& x!=rows-1)){
        if(arr[x-1][y]) counter++;
        if(arr[x+1][y]) counter++;
        if(arr[x][y-1]) counter++;
        if(arr[x-1][y-1]) counter++;
        if(arr[x+1][y-1]) counter++;
    }
    else if(x==rows-1 && (y!=0 && y!=columns-1)){
        if(arr[x][y-1]) counter++;
        if(arr[x][y+1]) counter++;
        if(arr[x-1][y]) counter++;
        if(arr[x-1][y-1]) counter++;
        if(arr[x-1][y+1]) counter++;
    }

    else if(x>0 && y >0 && x<rows-1 && y < columns-1)
    {
        if (arr[x - 1][y - 1]) counter++;
        if (arr[x - 1][y]) counter++;
        if (arr[x - 1][y + 1]) counter++;
        if (arr[x][y + 1]) counter++;
        if (arr[x + 1][y + 1]) counter++;
        if (arr[x + 1][y]) counter++;
        if (arr[x + 1][y - 1]) counter++;
        if (arr[x][y - 1]) counter++;
    }

    return counter;
}
