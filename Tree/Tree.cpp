#include "Tree.h"
Tree::Tree()
{
    root = NULL;
}
Tree& Tree::operator<<(int value)
{
    root = insert(root, value);
    return *this;
}
Tree::Node* Tree::insert(Node *node, int value)
{
    if(node == NULL)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if(value < node->data)
        node->left = insert(node->left, value);
    else if(value > node->data)
        node->right = insert(node->right, value);
    return node;
}
Tree& Tree::operator>>(int value)
{
    root = remove(root, value);
    return *this;
}
Tree::Node* Tree::remove(Node *node, int value)
{
    if(node == NULL)
    {
        cout << "Value not found!" << endl;
        return NULL;
    }
    if(value < node->data)
        node->left = remove(node->left, value);
    else if(value > node->data)
        node->right = remove(node->right, value);
    else
    {
        if(node->left == NULL && node->right == NULL)
        {
            delete node;
            return NULL;
        }
        else if(node->left == NULL)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if(node->right == NULL)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        else
        {
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }
    return node;
}
Tree::Node* Tree::findMin(Node *node)
{
    while(node->left != NULL)
        node = node->left;
    return node;
}
void Tree::inorder(Node *node, ostream &out)
{
    if(node != NULL)
    {
        inorder(node->left, out);
        out << node->data << " ";
        inorder(node->right, out);
    }
}
ostream& operator<<(ostream &out, Tree &t)
{
    out << "Tree (Inorder): ";
    t.inorder(t.root, out);
    return out;
}
