#include <iostream>

#include "graph.h"

int main()
{
    Graph g(10);

    Vertex *v1 = new Vertex("A");
    Vertex *v2 = new Vertex("B");
    Vertex *v3 = new Vertex("C");
    Vertex *v4 = new Vertex("D");
    Vertex *v5 = new Vertex("E");
    Vertex *v6 = new Vertex("F");
    Vertex *v7 = new Vertex("G");

    g.addVertex(v4);
    g.addVertex(v2);
    g.addVertex(v1);
    g.addVertex(v3);
    g.addVertex(v5);
    g.addVertex(v6);
    g.addVertex(v7);

    g.insertEdge(v1, v2, 1);
    g.insertEdge(v2, v3, 2);
    g.insertEdge(v3, v1, 3);
    g.insertEdge(v4, v5, 4);
    g.insertEdge(v5, v6, 5);
    g.insertEdge(v6, v4, 6);
    g.insertEdge(v7, v1, 7);
    g.insertEdge(v7, v2, 8);
    g.insertEdge(v7, v3, 9);
    g.insertEdge(v7, v4, 10);
    g.insertEdge(v7, v5, 11);
    g.insertEdge(v1, v4, 11);

    g.bfs();
    return 0;
}