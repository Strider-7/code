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

Node *create(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe)
{
    if (ps > pe)
    {
        return nullptr;
    }
    Node *node = new Node(postorder[pe]);
    int pos;
    for (int i = is; i <= ie; i++)
    {
        if (inorder[i] == node->data)
        {
            pos = i;
            break;
        }
    }
    node->left = create(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
    node->right = create(inorder, postorder, pos + 1, ie, pe - ie + pos, pe - 1);
    return node;
}
Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

int main()
{
    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->right->left = new Node(60);
    // root->right->right = new Node(70);
    // root->left->left = new Node(40);
    // root->left->right = new Node(50);
    // root->left->left->left = new Node(80);
    // root->left->left->right = new Node(90);
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Node *root = buildTree(inorder, postorder);

    return 0;
}
