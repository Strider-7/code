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

int res = 0;

int timeToBurn(Node *root, int leaf, int &dist)
{
    if (!root)
        return 0;
    if (root->data == leaf)
    {
        dist = 0;
        return 1;
    }

    int lDist = -1, rDist = -1;
    int lh = timeToBurn(root->left, leaf, lDist);
    int rh = timeToBurn(root->right, leaf, rDist);
    if (lDist != -1)
    {
        dist = lDist + 1;
        res = max(res, rh + dist);
    }
    if (rDist != -1)
    {
        dist = rDist + 1;
        res = max(res, lh + dist);
    }

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

    int x = 0;
    timeToBurn(root, 70, x);
    cout << res;

    return 0;
}
