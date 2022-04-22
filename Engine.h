#ifndef ENGINE_H
#define ENGINE_H

class Engine{

private:
    Engine(const Engine& engine);
    Engine& operator=(const Engine& engine);
    int checkNeighbors(int x, int y);

protected:
    bool** arr;
    bool** tmp;
    int rows;
    int columns;

protected:
    void Analyze();
    void Init();
    Engine(int rows, int columns);
    virtual ~Engine();

};
#endif // ENGINE_H
