#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <stack>
#include <vector>
#include "State.h"

class SearchTree
{
    public:
        SearchTree(int n);
        virtual ~SearchTree();

        int getExpanded();
        std::vector<int*> search();
    private:
        int n, expanded;
        State *root;

        std::vector<int*> backTracking(State* root);
};

#endif // SEARCHTREE_H
