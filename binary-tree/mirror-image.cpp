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
void preOrder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void mirror(Node* node)
{
    if (!node)
        return;
    mirror(node->right);
    mirror(node->left);
    Node *temp=node->left;
    node->left=node->right;
    node->right=temp;
}

Node* invertTree(Node* root) {
    if (!root) return NULL;

    Node* left = invertTree(root->left);
    Node* right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
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

    preOrder(root);
    cout<<endl;

    mirror(root);

    preOrder(root);




    return 0;
}
