#include <iostream>
#include "Tree.h"
using namespace std;
int main()
{
    Tree t;
    int choice;
    int value;
    do
    {
        cout << "\n------ TREE MENU ------" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Display Tree" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            t << value;
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            t >> value;
            break;
        case 3:
            cout << t << endl;
            break;
        case 4:
            cout << "Program Ended." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    }while(choice != 4);
    return 0;
}
