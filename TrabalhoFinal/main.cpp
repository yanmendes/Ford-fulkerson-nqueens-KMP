#include <iostream>
#include <sstream>
#include <chrono>
#include <vector>

#include "KMP.h"
#include "SearchTree.h"
#include "Network.h"

void evaluateKMP()
{
    int matches;
    double cpuTime;
    string file(""), text, pattern;
    std::clock_t startCpuTime;
    std::stringstream sstm;

    std::cout << "id, matches, time" << endl;

    for (int i = 1; i <= 36; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            sstm.str("");
            sstm.clear();
            sstm << "kmp/" << i << "-" << j;
            file = sstm.str();
            std::ifstream ifs(file.c_str());

            std::getline(ifs, text);
            std::getline(ifs, pattern);

            startCpuTime = std::clock();
            matches = KMP_search(text, pattern);
            cpuTime = (std::clock() - startCpuTime) / (double)CLOCKS_PER_SEC;

            std::cout << file << ", " << matches << ", " << cpuTime << endl;
        }

    }
}

void evaluateNQueens(int n)
{
    double cpuTime;
    vector<int*> solutions;
    std::clock_t startCpuTime;
    SearchTree* tree;

    std::cout << "n, solutions, expanded, time" << endl;

    for (int i = 15; i <= n; ++i)
    {
        tree = new SearchTree(i);

        startCpuTime = std::clock();
        solutions = tree->search();
        cpuTime = (std::clock() - startCpuTime) / (double)CLOCKS_PER_SEC;

        std::cout << i << ", " << solutions.size() << ", " << tree->getExpanded() << ", " << cpuTime << endl;

        solutions.clear();
        delete tree;
    }
}

void evaluateFordFulkerson()
{
    double cpuTime, flow;
    std::string file, files [] = {
        "0.000099502487562_1.max.bk",
        "0.000214490442462_1.max.bk",
        "0.000462361806570_1.max.bk",
        "0.000996680494109_1.max.bk",
        "0.002148473323752_1.max.bk",
        "0.004631311287980_1.max.bk",
        "0.009983388673736_1.max.bk",
        "0.021520481611665_1.max.bk",
        "0.046390173109900_1.max.bk",
        "printed_graph14.txt.max.bk",
        "printed_graph15.txt.max.bk",
        "printed_graph16.txt.max.bk",
        "printed_graph13.txt.max.bk",
        "printed_graph100.txt.max.bk",
        "printed_graph10.txt.max.bk",
        "printed_graph18.txt.max.bk",
        "printed_graph12.txt.max.bk",
        "printed_graph11.txt.max.bk",
        "printed_graph1.txt.max.bk",
        "printed_graph17.txt.max.bk",
        "printed_graph19.txt.max.bk",
        "rmf-wide.n2.3141.shuf.bk",
        "rmf-long.n2.3142.shuf.bk"
    };
    std::clock_t startCpuTime;
    Network* net;

    std::cout << "id, maxflow, time" << endl;

    for (int i = 0; i < 23; ++i)
    {
        file = files[i];
        net = new Network("fordfulkerson/" + file);

        startCpuTime = std::clock();
        flow = net->maxFlow();
        cpuTime = (std::clock() - startCpuTime) / (double)CLOCKS_PER_SEC;

        std::cout << i << ", " << flow << ", " << cpuTime << endl;

        delete net;
    }
}

int main()
{
    int opt;

    /// [1] KMP  -  [2] NQueens  -  [3] Ford Fulkerson
    std::cin >> opt;

    if (opt == 1)
        evaluateKMP();
    else if (opt == 2)
        evaluateNQueens(15);
    else if (opt == 3)
        evaluateFordFulkerson();

    return 0;
}
