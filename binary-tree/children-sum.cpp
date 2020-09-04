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

bool childrenSum(Node *root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
        
    int sum = 0;
    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;

    return root->data == sum && childrenSum(root->left) && childrenSum(root->right);
}

int main()
{
    Node *root = new Node(70);
    root->left = new Node(40);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(15);
    root->left->left = new Node(10);
    root->left->right = new Node(30);

    cout << childrenSum(root);

    return 0;
}
