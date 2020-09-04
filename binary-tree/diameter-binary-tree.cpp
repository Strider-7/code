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

int diameter(Node *root)
{
    if (!root)
        return true;
    int x, y;
    x = height(root->left);
    y = height(root->right);
    cout << x << " " << y << endl;

    return max({1 + x + y, diameter(root->left), diameter(root->right)});
}

int height2(Node *root, int &res)
{
    if (!root)
        return 0;
    int lh = height2(root->left, res);
    int rh = height2(root->right, res);
    res = max(res, 1+lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(Node *root)
{
    int res = 0;
    height2(root, res);
    return res;
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
    // root->left->left->left = new Node(80);
    // root->left->left->right = new Node(90);

    // cout << diameter(root);
    cout << endl;
    cout << diameterOfBinaryTree(root);

    return 0;
}
