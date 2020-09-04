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

Node *inOrderSuccessor(Node *node)
{
    while (node && node->left)
    {
        node = node->left;
    }
    return node;
}

Node *inOrderPredecessor(Node *node)
{
    while (node && node->left)
    {
        node = node->left;
    }
    return node;
}

Node * deleteNode(Node *root, int k) {
    if (!root)
        return nullptr;
    if (k<root->data)
        root->left=deleteNode(root->left, k);
    else if (k>root->data)
        root->right=deleteNode(root->right, k);
    else
    {
        if (!root->left)
        {
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp=inOrderSuccessor(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right, temp->data);
        }
        return root;
    }




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
    root=insert(root, 5);
    for (int i=0;i<5;i++)
        root=insert(root, i);
    for (int i=6;i<10;i++)
        root=insert(root, i);

    preOrder(root);

    deleteNode(root, 7);
    cout<<endl;

    preOrder(root);


    return 0;
}