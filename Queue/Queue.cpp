#include "Queue.h"
Queue::Queue()
{
    front = -1;
    rear = -1;
}
bool Queue::isEmpty()
{
    return front == -1;
}
bool Queue::isFull()
{
    return rear == 99;
}
Queue& Queue::operator<<(int value)
{
    if (isFull())
    {
        cout << "Queue Overflow!" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;
        arr[++rear] = value;
    }
    return *this;
}
Queue& Queue::operator>>(int &value)
{
    if (isEmpty())
    {
        cout << "Queue Underflow!" << endl;
        value = -1;
    }
    else
    {
        value = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
    return *this;
}
ostream& operator<<(ostream &out, Queue &q)
{
    if (q.isEmpty())
    {
        out << "Queue is Empty";
    }
    else
    {
        out << "Queue: ";
        for (int i = q.front; i <= q.rear; i++)
        {
            out << q.arr[i] << " ";
        }
    }
    return out;
}
