#include <iostream>
using namespace std;
int graph[20][20];
int visited[20] = {0};
int n;
void DFS(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = 1;
    for(int i = 0; i < n; i++)
    {
        if(graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}
int main()
{
    int start;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    cout << "Enter the starting vertex (0 to " << n - 1 << "): ";
    cin >> start;
    cout << "DFS traversal: ";
    DFS(start);
    return 0;
}