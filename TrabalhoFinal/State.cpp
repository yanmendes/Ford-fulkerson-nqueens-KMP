#include <stdlib.h>
#include "State.h"

State::State(int n, int depth)
{
    this->n = n;
    this->depth = depth;

    childCount = 0;
    gen_column = 0;
    board = new int[n];
    child = nullptr;
}

State::~State()
{
    delete []board;
}

void State::printBoard()
{
    std::cout << "[ ";

    for(int i = 0; i < n; ++i)
        std::cout<< board[i] << " ";

    std::cout << "]" << std::endl;
}

bool State::hasConflicts()
{
    for (int i = 0; i < depth; ++i)
        for (int j = i + 1; j < depth; ++j)
            if (board[i] == board[j] || (j - i == abs(board[j] - board[i])))
                return true;

    return false;
}

bool State::isSolution()
{
    if (depth < n) return false;

    return !hasConflicts();
}

State* State::makeNextChild()
{
    State* newState;

    delete child;

    for (; gen_column < n; ++gen_column)
    {
        newState = makeChild(gen_column);

        if (newState != nullptr)
        {
            child = newState;
            ++gen_column;

            return newState;
        }
    }

    return nullptr;
}

State* State::makeChild(int column)
{
    State* child = new State(n, depth + 1);

    for (int i = 0; i < depth; ++i)
        child->setQueen(i, board[i]);

    child->setQueen(depth, column);

    if (child->hasConflicts())
    {
        delete child;
        return nullptr;
    }
    else
        return child;
}

// getters and setters

void State::setQueen(int line, int column)
{
    board[line] = column;
}
