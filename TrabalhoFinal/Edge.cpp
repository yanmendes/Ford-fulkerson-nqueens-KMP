#include "Edge.h"


Edge::Edge(int id, int tail, int head, double capacity)
{
    this->id = id;
    this->tail = tail;
    this->head = head;
    this->capacity = capacity;
}

Edge::~Edge()
{
    //dtor
}

int Edge::getId()
{
    return id;
}

int Edge::getTail()
{
    return tail;
}

int Edge::getHead()
{
    return head;
}

double Edge::getCapacity()
{
    return capacity;
}

Edge* Edge::getNext()
{
    return next;
}

void Edge::setNext(Edge* edge)
{
    next = edge;
}

Edge* Edge::getRedge()
{
    return redge;
}

void Edge::setRedge(Edge* redge)
{
    this->redge = redge;
}
