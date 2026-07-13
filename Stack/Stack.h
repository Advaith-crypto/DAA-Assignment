#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
class Stack
{
private:
    int arr[100];
    int top;
public:
    Stack();
    bool isEmpty();
    bool isFull();
    Stack& operator<<(int value);     
    Stack& operator>>(int &value);    
    friend ostream& operator<<(ostream &out, Stack &s);
};
#endif
