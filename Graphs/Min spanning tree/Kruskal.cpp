#include <iostream>
using namespace std;
struct Edge {
    int u;
    int v;
    int weight;
};
int findParent(int parent[], int vertex) {
    if (parent[vertex] == vertex)
        return vertex;
    return parent[vertex] = findParent(parent, parent[vertex]);
}
void unionSets(int parent[], int rank[], int u, int v) {
    int parentU = findParent(parent, u);
    int parentV = findParent(parent, v);
    if (parentU == parentV)
        return;
    if (rank[parentU] < rank[parentV])
        parent[parentU] = parentV;
    else if (rank[parentU] > rank[parentV])
        parent[parentV] = parentU;
    else {
        parent[parentV] = parentU;
        rank[parentU]++;
    }
}
void sortEdges(Edge edges[], int edgesCount) {
    for (int i = 0; i < edgesCount - 1; i++) {
        for (int j = 0; j < edgesCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}
void kruskal(Edge edges[], int vertices, int edgesCount) {
    int parent[10];
    int rank[10] = {0};
    for (int i = 0; i < vertices; i++)
        parent[i] = i;
    sortEdges(edges, edgesCount);
    int totalWeight = 0;
    int selectedEdges = 0;
    cout << "\nMinimum Spanning Tree:\n";
    for (int i = 0; i < edgesCount && selectedEdges < vertices - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (findParent(parent, u) != findParent(parent, v)) {
            cout << u << " - " << v << " : " << edges[i].weight << "\n";
            totalWeight += edges[i].weight;
            selectedEdges++;
            unionSets(parent, rank, u, v);
        }
    }

    cout << "Total weight: " << totalWeight << endl;
}
int main() {
    int vertices, edgesCount;
    Edge edges[45];
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edgesCount;
    cout << "Enter the edges with their weights:\n";
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    kruskal(edges, vertices, edgesCount);
    return 0;
}