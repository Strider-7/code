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

int sum(Node *root, int k, int &res) {
    if (!root)
        return 0;

    int curr=root->data+sum(root->left, k, res)+sum(root->right, k, res);

    if (curr==k)
        res++;
    return curr;
}

int countSubtreesWithSumX(Node* root, int k)
{
    int res=0;
    sum(root, k, res);
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


    cout<<countSubtreesWithSumX(root,160);

    return 0;
}


