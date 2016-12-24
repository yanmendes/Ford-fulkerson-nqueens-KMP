#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

#include "Vertex.h"

using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::unordered_set;
using std::unordered_map;


class Network
{
    public:
        Network();
        Network(string file);
        ~Network();

        void addVertex(int vertex);
        void addEdge(int tail, int head, double capacity);
        double maxFlow();
        double maxFlow(int source, int sink);
    private:
        int firstVertex, lastVertex, edgeId;
        unordered_map<int,Vertex*> vertexMap;
        unordered_map<int,double> flow;

        void loadFromFile(string file);
        double pathCapacity(vector<Edge*>& path);
        vector<Edge*> findPath(int source, int sink);
        Vertex* getVertex(int vertex);
};

#endif // GRAPH_H
