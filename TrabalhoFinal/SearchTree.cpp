#include "SearchTree.h"
//#define _UNIX
SearchTree::SearchTree(int n)
{
    this->n = n;
    expanded = 0;
    root = new State(n, 0);

    for (int i = 0; i < n; ++i) root->setQueen(i, -1);
}

SearchTree::~SearchTree()
{
    delete root;
}

int SearchTree::getExpanded()
{
    return expanded;
}

std::vector<int*> SearchTree::search()
{
    return backTracking(root);
}

std::vector<int*> SearchTree::backTracking(State* root)
{
    State* current, *child;
    std::stack<State*> s;
    std::vector<int*> solutions;

    s.push(root);

    while (!s.empty())
    {
        current = s.top();

        if (current->isSolution())
        {
            solutions.push_back(current->getBoard());
            s.pop();
            continue;
        }

        if ((child = current->makeNextChild()))
        {
            ++expanded;
            s.push(child);
        }
        else
            s.pop();
    }

    return solutions;
}
