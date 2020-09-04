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

Node * insert2(Node *root, int k)
{
    if (!root)
        return new Node(k);
    Node *parent=nullptr, *curr=root;
    while (curr)
    {
        parent=curr;
        if (curr->data==k)
            return nullptr;
        else if (k<curr->data)
            curr=curr->left;
        else
            curr=curr->right;
    }
    if (k<parent->data)
        parent->left=new Node(k);
    else
        parent->right=new Node(k);



    return root;

}

void preOrder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root=nullptr;
    root=insert2(root, 5);
    for (int i=0;i<5;i++)
        root=insert2(root, i);
    for (int i=6;i<10;i++)
        root=insert2(root, i);

    preOrder(root);

    return 0;
}