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

Node *search(Node *root, int key)
{
    if (!root || root->data == key)
        return root;
    Node *p = search(root->left, key);
    if (p)
        return p;
    else
        return search(root->right, key);
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

    search(root, 80) ? cout << "found" : cout << "not found";

    return 0;
}
