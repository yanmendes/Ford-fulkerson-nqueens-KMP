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
        int* getBoard();
        State* makeNextChild();
        State* makeChild(int column);

        // getters and setters
        void setQueen(int line, int column);

    private:
        bool solution;
        int n, childCount, depth, genColumn;
        int *board;
        State *child;

        bool hasConflicts();
        bool lastQueenHasConflicts();
};

#endif // STATE_H
