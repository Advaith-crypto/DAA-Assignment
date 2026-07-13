#include "Graph.h"
Graph::Graph(int v)
{
    vertices = v;
    initialize();
}
void Graph::initialize()
{
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            adj[i][j] = 0;
        }
    }
}
Graph& Graph::operator<<(pair<int,int> edge)
{
    int u = edge.first;
    int v = edge.second;
    if(u >= vertices || v >= vertices)
    {
        cout << "Invalid vertex!" << endl;
    }
    else
    {
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }
    return *this;
}
Graph& Graph::operator>>(pair<int,int> edge)
{
    int u = edge.first;
    int v = edge.second;
    if(u >= vertices || v >= vertices)
    {
        cout << "Invalid vertex!" << endl;
    }
    else
    {
        adj[u][v] = 0;
        adj[v][u] = 0;
    }
    return *this;
}
ostream& operator<<(ostream &out, Graph &g)
{
    out << "\nAdjacency Matrix:\n";
    for(int i = 0; i < g.vertices; i++)
    {
        for(int j = 0; j < g.vertices; j++)
        {
            out << g.adj[i][j] << " ";
        }
        out << endl;
    }
    return out;
}
