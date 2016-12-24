#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.h"

class Vertex
{
    public:
        Vertex(int vertex);
        ~Vertex();

        void addAdjacency(int head, double capacity, int id);
        Edge* getFirstEdge();
    private:
        int vertex;
        Edge* firstEdge;
};

#endif // VERTEX_H
