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
// Time -O(no. of nodes), Space-O(height)
int size(Node *root)
{

    if (!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << size(root);

    return 0;
}
