#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[n][n];

    cout << "Enter the adjacency matrix using only 0 and 1:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];

            if (i != j && graph[i][j] == 0)
                graph[i][j] = 99999;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != 99999 && graph[k][j] != 99999 &&
                    graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 99999)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}