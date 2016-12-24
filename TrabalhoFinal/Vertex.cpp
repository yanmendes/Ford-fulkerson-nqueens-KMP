#include "Vertex.h"

Vertex::Vertex(int vertex)
{
    this->vertex = vertex;
    firstEdge = nullptr;
}

Vertex::~Vertex()
{
    Edge *aux, *edge = firstEdge;

    firstEdge = nullptr;

    while (edge != nullptr)
    {
        aux = edge;
        edge = edge->getNext();

        delete aux;
    }
}

void Vertex::addAdjacency(int head, double capacity, int id)
{
    Edge* edge = new Edge(id, vertex, head, capacity);
    edge->setNext(firstEdge);

    firstEdge = edge;
}

Edge* Vertex::getFirstEdge()
{
    return firstEdge;
}
