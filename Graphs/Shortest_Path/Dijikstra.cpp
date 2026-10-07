#include <iostream>
using namespace std;

#define INF 9999

void dijkstra(int graph[][10], int vertices, int start) {
    int distance[10];
    bool visited[10] = {false};

    for (int i = 0; i < vertices; i++)
        distance[i] = INF;

    distance[start] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int minimum = INF;
        int current = -1;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && distance[i] < minimum) {
                minimum = distance[i];
                current = i;
            }
        }

        if (current == -1)
            break;

        visited[current] = true;

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] != 0 && !visited[i]) {
                int newDistance = distance[current] + graph[current][i];

                if (newDistance < distance[i])
                    distance[i] = newDistance;
            }
        }
    }

    cout << "\nShortest distances from vertex " << start << ":\n";

    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INF)
            cout << start << " -> " << i << " : Unreachable\n";
        else
            cout << start << " -> " << i << " : " << distance[i] << "\n";
    }
}

int main() {
    int vertices, edges;
    int graph[10][10] = {0};

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges with their weights:\n";

    for (int i = 0; i < edges; i++) {
        int u, v, weight;

        cin >> u >> v >> weight;

        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int start;

    cout << "Enter the starting vertex: ";
    cin >> start;

    dijkstra(graph, vertices, start);

    return 0;
}