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

Node *insert(Node *root, int data) {
    if (!root)
        return new Node(data);

    if (data==root->data)
        return nullptr;

    else if (data<root->data)
        root->left=insert(root->left, data);

    else
        root->right=insert(root->right, data);

    return root;

}


// wrong only checks for adjacent nodes not nodes at level 2 or more below
// bool isBST(Node *root) {
//     if (!root)
//         return true;
//     if (!root->left && !root->right)
//         return true;

//     bool x=true, y=true;
//     if (root->left)
//         x=root->data>root->left->data;
//     if (root->right)
//         y=root->data<root->right->data;

//     return x && y  &&  isBST(root->left) && isBST(root->right);

// }

int maximum(Node *root)
{
    if (!root)
        return INT32_MIN;

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(Node *root)
{
    if (!root)
        return INT32_MAX;

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
// O(n^2)
bool isBST(Node *root) {
    if (!root)
        return true;

    return root->data >maximum(root->left) && root->data<minimum(root->right) && isBST(root->left) && isBST(root->right);
}
// best solution
bool BSTcheck(Node *root, int low, int high) {
    if (!root)
        return true;

    return root->data>low && root->data <high && BSTcheck(root->left, low, root->data) &&BSTcheck(root->right, root->data, high);
}


int main() {
    Node *root1=nullptr;
    root1=insert(root1, 5);
    for (int i=0;i<5;i++)
        root1=insert(root1, i);
    for (int i=6;i<10;i++)
        root1=insert(root1, i);



    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(30);
    // root->left->right = new Node(40);
    // root->left->right->left = new Node(37);
    // root->left->right->right = new Node(45);
    root->right->right = new Node(35);
    root->right->left = new Node(18);

    // cout<<isBST(root1)<<endl;
    // cout<<isBST(root)<<endl;

    cout<<BSTcheck(root1, INT32_MIN, INT32_MAX)<<endl;
    cout<<BSTcheck(root, INT32_MIN, INT32_MAX)<<endl;




    return 0;
}