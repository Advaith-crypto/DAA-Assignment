#include "Stack.h"
Stack::Stack()
{
    top = -1;
}
bool Stack::isEmpty()
{
    return top == -1;
}
bool Stack::isFull()
{
    return top == 99;
}
Stack& Stack::operator<<(int value)
{
    if (isFull())
        cout << "Stack Overflow!" << endl;
    else
        arr[++top] = value;
    return *this;
}
Stack& Stack::operator>>(int &value)
{
    if (isEmpty())
        cout << "Stack Underflow!" << endl;
    else
        value = arr[top--];
    return *this;
}
ostream& operator<<(ostream &out, Stack &s)
{
    if (s.isEmpty())
    {
        out << "Stack is Empty";
    }
    else
    {
        out << "Stack: ";
        for (int i = s.top; i >= 0; i--)
            out << s.arr[i] << " ";
    }
    return out;
}
