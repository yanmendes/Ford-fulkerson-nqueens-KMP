#include "Network.h"

Network::Network()
{
    edgeId = 0;
}

Network::Network(string file)
{
    edgeId = 0;
    loadFromFile(file);
}

Network::~Network()
{
    for (auto it = vertexMap.begin(); it != vertexMap.end(); ++it)
        delete it->second;
}

void Network::addVertex(int vertex)
{
    vertexMap[vertex] = new Vertex(vertex);
}

void Network::addEdge(int tail, int head, double capacity)
{
    Vertex* vTail = getVertex(tail);
    Vertex* vHead = getVertex(head);

    flow[edgeId] = 0;
    vTail->addAdjacency(head, capacity, edgeId++);
    flow[edgeId] = 0;
    vHead->addAdjacency(tail, 0, edgeId++);

    vTail->getFirstEdge()->setRedge(vHead->getFirstEdge());
    vHead->getFirstEdge()->setRedge(vTail->getFirstEdge());
}

double Network::maxFlow()
{
    return maxFlow(firstVertex, lastVertex);
}

double Network::maxFlow(int source, int sink)
{
    int maxFlow = 0, pathFlow;
    vector<Edge*> path = findPath(source, sink);
    Edge* edge;

    while(!path.empty())
    {
        pathFlow = pathCapacity(path);
        for (auto it = path.begin() + 1; it != path.end(); ++it)
        {
            edge = *it;
            flow[edge->getId()] += pathFlow;
            flow[edge->getRedge()->getId()] -= pathFlow;
        }

        path = findPath(source, sink);
    }

    for (edge = vertexMap[source]->getFirstEdge(); edge != NULL; edge = edge->getNext())
        maxFlow += flow[edge->getId()];

    return maxFlow;
}

void Network::loadFromFile(string file)
{
    int nVertex, nEdges, vertex, head, tail;
    double capacity;
    string type, discard;
    std::ifstream stream(file.c_str());

    stream >> type >> nVertex >> nEdges;

    firstVertex = nVertex;
    lastVertex = 0;

    while (stream >> type)
    {
        if (type == "n")
        {
            stream >> vertex;
            addVertex(vertex);
            stream >> discard >> discard;
        }
        else if (type == "a")
        {
            stream >> tail >> head >> capacity;

            if (capacity == 0)
                stream >> capacity;
            else
                stream >> discard;

            addEdge(tail, head, capacity);

            firstVertex = (firstVertex > tail) ? tail : firstVertex;
            lastVertex = (lastVertex < head) ? head : lastVertex;
        }
    }

    stream.close();
}

double Network::pathCapacity(vector<Edge*>& path)
{
    Edge* edge = (*path.begin());
    double residual = edge->getCapacity() - flow[edge->getId()], capacity = residual;

    for (auto it = path.begin() + 1; it != path.end(); ++it)
    {
        edge = *it;
        residual = edge->getCapacity() - flow[edge->getId()];

        if (residual < capacity)
            capacity = residual;
    }

    return capacity;
}

vector<Edge*> Network::findPath(int source, int sink)
{
    bool sinkFound = false;
    int tail, head;
    vector<Edge*> path;
    queue<int> queue;
    unordered_set<int> visited;
    unordered_map<int,Edge*> parent;
    Edge* edge;

    visited.reserve(vertexMap.size());

    queue.push(source);
    visited.insert(source);

    while(!queue.empty())
    {
        tail = queue.front();
        queue.pop();

        for(edge = vertexMap[tail]->getFirstEdge(); edge != nullptr; edge = edge->getNext())
        {
            head = edge->getHead();

            if (visited.find(head) == visited.end() && (edge->getCapacity() - flow[edge->getId()]) > 0)
            {
                visited.insert(head);
                parent[head] = edge;
                queue.push(head);

                if (head == sink)
                {
                    sinkFound = true;
                    break;
                }
            }
        }

        if (sinkFound)
            break;
    }

    if (sinkFound)
    {
        while(parent[sink]->getTail() != source)
        {
            path.push_back(parent[sink]);
            sink = parent[sink]->getTail();
        }

        path.push_back(parent[sink]);
    }

    return path;
}

Vertex* Network::getVertex(int vertex)
{
    Vertex* v = vertexMap[vertex];

    if (v == NULL)
    {
        v = new Vertex(vertex);
        vertexMap[vertex] = v;
    }

    return v;
}
