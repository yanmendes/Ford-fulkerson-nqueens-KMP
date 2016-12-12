#include "SearchTree.h"
//#define _UNIX
SearchTree::SearchTree(int n)
{
    this->n = n;
    this->expanded = 0;
    this->searchCpuTime = this->searchWallTime = 0;
    this->root = new State(n, 0);

    for (int i = 0; i < n; ++i) root->setQueen(i, -1);
}

SearchTree::~SearchTree()
{
    delete root;
}

State* SearchTree::search()
{
    double startT, finishT;
    #ifdef __unix
    timespec startWallTime, finishWallTime;
    clock_gettime(CLOCK_MONOTONIC, &startWallTime);
    #else
    GET_TIME(startT);
    #endif
    std::clock_t startCpuTime = std::clock();

    solution = backTracking(root);

    searchCpuTime = (std::clock() - startCpuTime) / (double)CLOCKS_PER_SEC;
    #ifdef __unix
    clock_gettime(CLOCK_MONOTONIC, &finishWallTime);
    searchWallTime = (finishWallTime.tv_sec - startWallTime.tv_sec) + (finishWallTime.tv_nsec - startWallTime.tv_nsec) / 1000000000.0;
    #else
    GET_TIME(finishT);
    searchWallTime = finishT - startT;
    #endif

    return solution;
}

State* SearchTree::backTracking(State* root)
{
    State* current, *child;
    std::stack<State*> s;

    s.push(root);

    while (!s.empty())
    {
        current = s.top();

        if (current->isSolution())
            return current;

        if (child = current->makeNextChild())
        {
            ++expanded;
            s.push(child);
        }
        else
            s.pop();
    }

    return nullptr;
}
