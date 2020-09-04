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

int maximum(Node *root)
{
    if (!root)
        return INT32_MIN;

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    // cout << size(root) << endl;
    cout << maximum(root) << endl;

    return 0;
}
