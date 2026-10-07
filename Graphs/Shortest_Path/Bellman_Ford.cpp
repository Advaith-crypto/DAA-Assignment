#include <iostream>
using namespace std;

#define INF 9999

struct Edge {
    int u;
    int v;
    int weight;
};

void bellmanFord(Edge edges[], int vertices, int edgesCount, int start) {
    int distance[10];

    for (int i = 0; i < vertices; i++)
        distance[i] = INF;

    distance[start] = 0;

    for (int i = 1; i <= vertices - 1; i++) {
        bool updated = false;

        for (int j = 0; j < edgesCount; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                updated = true;
            }
        }

        if (!updated)
            break;
    }

    for (int i = 0; i < edgesCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            cout << "\nNegative-weight cycle detected.\n";
            return;
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
    int vertices, edgesCount;
    Edge edges[45];

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    cout << "Enter the edges with their weights:\n";

    for (int i = 0; i < edgesCount; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    int start;

    cout << "Enter the starting vertex: ";
    cin >> start;

    bellmanFord(edges, vertices, edgesCount, start);

    return 0;
}