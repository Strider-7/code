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



void swapNodes(Node *root) {
    Node *prev=nullptr, *first=nullptr, *second=nullptr;
    fixBST(root, prev, first, second);
    int x=first->data;
    first->data=second->data;
    second->data=x;

}

void fixBST(Node *root, Node* &prev, Node* &first, Node* &second) {
    if (!root)
        return;
    fixBST(root->left, prev, first, second);
    if (prev &&root->data<prev->data) {
        if (!first)
            first=prev;
        second=root;
    }
    prev=root;
    fixBST(root->right, prev, first, second);
}

bool BSTcheck(Node *root, int low, int high) {
    if (!root)
        return true;

    return root->data>low && root->data <high && BSTcheck(root->left, low, root->data) &&BSTcheck(root->right, root->data, high);
}


int main() {

    Node *root=nullptr;

    root=insert(root, 40);
    root=insert(root, 30);
    root=insert(root, 60);
    root=insert(root, 50);
    root=insert(root, 70);
    root=insert(root, 20);
    root=insert(root, 10);
   



    cout<<BSTcheck(root, INT32_MIN, INT32_MAX)<<endl;







    return 0;
}