#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;
class Graph
{
private:
    int adj[100][100];
    int vertices;
public:
    Graph(int v);
    void initialize();
    Graph& operator<<(pair<int,int> edge);
    Graph& operator>>(pair<int,int> edge);
    friend ostream& operator<<(ostream &out, Graph &g);
};
#endif
