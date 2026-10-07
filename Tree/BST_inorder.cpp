#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }
    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node* root = NULL;
    int n, value;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }
    cout << "In-order traversal: ";
    inorder(root);
    return 0;
}