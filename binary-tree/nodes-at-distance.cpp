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

int height(Node *root, int k, int &res) {
    if (!root)
        return 0;
    int lh=height(root->left, k, res);
    int rh=height(root->right, k, res);
    if (lh==k||rh==k)
        res++;
    return 1+max(lh, rh);
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

    int res=0;
    height(root, 1, res);
    cout<<res;



    return 0;
}


