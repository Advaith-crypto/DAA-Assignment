#ifndef TREE_H
#define TREE_H
#include <iostream>
using namespace std;
class Tree
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
    };
    Node *root;
    Node* insert(Node *node, int value);
    Node* remove(Node *node, int value);
    Node* findMin(Node *node);
    void inorder(Node *node, ostream &out);
public:
    Tree();
    Tree& operator<<(int value); 
    Tree& operator>>(int value);   
    friend ostream& operator<<(ostream &out, Tree &t);
};
#endif
