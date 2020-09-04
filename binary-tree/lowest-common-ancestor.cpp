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

bool findPath(Node *root, vector<Node *> &path, int k)
{
    // base case
    if (root == NULL)
        return false;

    // Store this node in path vector. The node will be removed if
    // not in path from root to k
    path.push_back(root);

    // See if the k is same as root's key
    if (root->data == k)
        return true;

    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k)) ||
        (root->right && findPath(root->right, path, k)))
        return true;

    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
}

Node *findLCA(Node *root, int n1, int n2)
{
    // to store paths to n1 and n2 from the root
    vector<Node *> path1, path2;

    // Find paths from root to n1 and root to n1. If either n1 or n2
    // is not present, return -1
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return nullptr;

    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1];
}

Node *LCA(Node *root, int x, int y)
{
    if (!root)
        return nullptr;

    if (root->data == x || root->data == y)
        return root;

    Node *lca1 = LCA(root->left, x, y);
    Node *lca2 = LCA(root->right, x, y);

    if (lca1 && lca2)
        return root;

    if (lca1)
        return lca1;
    else
        return lca2;
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

    cout << findLCA(root, 40, 60)->data << endl;
    cout << LCA(root, 40, 60)->data;
    return 0;
}
