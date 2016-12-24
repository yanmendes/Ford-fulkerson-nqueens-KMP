#ifndef EDGE_H
#define EDGE_H

class Edge
{
    public:
        Edge(int id, int tail, int head, double capacity);
        ~Edge();

        int getId();
        int getTail();
        int getHead();
        double getCapacity();
        Edge* getNext();
        void setNext(Edge* edge);
        Edge* getRedge();
        void setRedge(Edge* redge);
    private:
        int id, tail, head;
        double capacity;
        Edge* redge;
        Edge* next;
};

#endif // EDGE_H
