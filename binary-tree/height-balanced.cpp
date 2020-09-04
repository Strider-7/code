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

int height(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
// O(n^2)
bool heightBalanced(Node *root)
{
    if (!root)
        return true;
    int x, y;
    x = height(root->left);
    y = height(root->right);
    return abs(x - y) <= 1 && heightBalanced(root->left) && heightBalanced(root->right);
}

int isBalanced(Node *root)
{
    if (!root)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return 1 + max(lh, rh);
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

    cout << heightBalanced(root)<<endl;
    cout << isBalanced(root);

    return 0;
}
