#ifndef STATE_H
#define STATE_H

#include <iostream>

class State
{
    public:
        State(int n, int depth);
        virtual ~State();

        void printBoard();
        bool isSolution();
        State* makeNextChild();
        State* makeChild(int column);

        // getters and setters
        void setQueen(int line, int column);

    private:
        int n, childCount, depth, gen_column;
        int *board;
        State *child;

        bool hasConflicts();
};

#endif // STATE_H
