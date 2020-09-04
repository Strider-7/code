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
Node *prev = nullptr;

void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
// Inorder
Node *convertToLL(Node *root)
{
    static Node *prev = nullptr;
    if (!root)
        return root;

    Node *head = convertToLL(root->left);
    if (!prev)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    convertToLL(root->right);

    return head;
}
// preOrder
void flatten(Node *root)
{
    if (!root || (!root->left && !root->right))
        return;

    Node *temp = root->right;

    root->right = root->left;
    root->left = NULL;

    flatten(root->right);

    while (root->right)
        root = root->right;

    root->right = temp;

    flatten(root->right);
}

void display(Node *node)
{
    while (node)
    {
        cout << node->data << " ";
        node = node->right;
    }
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
    root->left->left->left = new Node(80);
    root->left->left->right = new Node(90);
    inOrder(root);
    cout << endl;

    root = convertToLL(root);
    display(root);

    return 0;
}
