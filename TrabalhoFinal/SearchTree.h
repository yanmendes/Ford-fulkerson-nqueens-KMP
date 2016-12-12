#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <chrono>
#include <stack>
#include "State.h"

class SearchTree
{
    public:
        SearchTree(int n);
        virtual ~SearchTree();

        State* search();

    private:
        int n, expanded;
        double searchCpuTime, searchWallTime;
        State *root, *solution;

        State* backTracking(State* root);
};

#endif // SEARCHTREE_H
