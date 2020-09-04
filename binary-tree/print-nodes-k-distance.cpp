#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void printNodesAtKDistance(Node *root, int k, int count = 0)
{
    if (!root)
        return;

    if (count == k)
    {
        cout << root->data << " ";
        return;
    }
    printNodesAtKDistance(root->left, k, count + 1);
    printNodesAtKDistance(root->right, k, count + 1);
}

void printKDist(Node *root, int k)
{
    if (!root)
        return;
    if (k == 0)
        cout << root->data << " ";
    else
    {
        printKDist(root->left, k - 1);
        printKDist(root->right, k - 1);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    // printNodesAtKDistance(root, 2);
    printKDist(root, 2);

    return 0;
}
