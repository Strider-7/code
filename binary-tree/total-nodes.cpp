// total nodes in a complete binary tree
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

int totalNodes(Node *root) {
    if (!root)
        return 0;
    return 1+ totalNodes(root->left)+totalNodes(root->right);
}

int totalNodes2(Node *root) {
    int lh=0, rh=0;
    Node *p=root;
    while (p)
    {
        lh++;
        p=p->left;
    }
    p=root;
    while (p)
    {
        rh++;
        p=p->right;
    }
    if (lh==rh)
        return pow(2, lh)-1;

    return 1+totalNodes2(root->left)+totalNodes(root->right);


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

    cout<<totalNodes(root)<<endl;

    cout<<totalNodes2(root)<<endl;

    return 0;
}
