#include "Graph.h"
int main()
{
    int vertices, choice;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    Graph g(vertices);
    do
    {
        cout << "1. Add Edge" << endl;
        cout << "2. Remove Edge" << endl;
        cout << "3. Display Adjacency Matrix" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                int u, v;
                cout << "Enter the two vertices to connect: ";
                cin >> u >> v;
                g << make_pair(u, v);
                break;
            }
            case 2:
            {
                int u, v;
                cout << "Enter the two vertices to disconnect: ";
                cin >> u >> v;
                g >> make_pair(u, v);
                break;
            }
            case 3:
            {
                cout << g;
                break;
            }
            case 4:
            {
                cout << "Exiting..." << endl;
                break;
            }
            default:
            {
                cout << "Invalid choice!" << endl;
            }
        }

    }while(choice != 4);
    return 0;
}