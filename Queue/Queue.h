#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
class Queue
{
private:
    int arr[100];
    int front;
    int rear;
public:
    Queue();
    bool isEmpty();
    bool isFull();
    Queue& operator<<(int value);    
    Queue& operator>>(int &value);    
    friend ostream& operator<<(ostream &out, Queue &q);
};
#endif
