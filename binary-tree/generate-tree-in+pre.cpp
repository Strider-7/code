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

int search(int arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

Node *buildTree(int in[], int pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

    /* Pick current node from Preorder 
	traversal using preIndex 
	and increment preIndex */
    Node *tNode = new Node(pre[preIndex++]);

    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;

    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    /* Using index in Inorder traversal, construct left and 
	right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main()
{
    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->right->left = new Node(60);
    // root->right->right = new Node(70);
    // root->left->left = new Node(40);
    // root->left->right = new Node(50);
    // root->left->left->left = new Node(80);
    // root->left->left->right = new Node(90);
    int pre[] = {3, 9, 20, 15, 7};
    int in[] = {9, 3, 15, 20, 7};
    int n = sizeof(pre) / sizeof(pre[0]);

    Node *root = nullptr;
    root = buildTree(in, pre, 0, n - 1);

    inOrder(root);

    return 0;
}
