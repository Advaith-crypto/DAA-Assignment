#include "Stack.h"
int main()
{
    Stack s;
    int choice, value;
    do
    {
        cout << "\nSelect any one option:-" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << "Enter the value to push: ";
                cin >> value;
                s << value;
                break;
            }
            case 2:
            {
                if(!s.isEmpty())
                {
                    s >> value;
                    cout << "Popped Element: " << value << endl;
                }
                else
                {
                    s >> value;
                }
                break;
            }
            case 3:
            {
                cout << s << endl;
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

    } while(choice != 4);
    return 0;
}