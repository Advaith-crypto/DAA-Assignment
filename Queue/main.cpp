#include "Queue.h"
int main()
{
    Queue q;
    int choice, value;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << "Enter the value to enqueue: ";
                cin >> value;
                q << value;
                break;
            }
            case 2:
            {
                q >> value;
                if(value != -1)
                {
                    cout << "Dequeued Element: " << value << endl;
                }
                break;
            }
            case 3:
            {
                cout << q << endl;
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