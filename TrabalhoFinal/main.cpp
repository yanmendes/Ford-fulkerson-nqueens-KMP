#include <iostream>

#include "KMP.h"
#include "SearchTree.h"

int main()
{
    std::cout << KMP_search("Arthur Lorenzi", "Lorenzi") << std::endl;
    SearchTree* t = new SearchTree(8);
    t->search()->printBoard();

    delete t;

    return 0;
}
