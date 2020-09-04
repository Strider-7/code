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

struct NodeDetails
{
    Node *ptr;
    int min, max;
};

Node* constructBst(int arr[], int n)
{
    // base case
    if (n == 0)return NULL;
    Node *root;

    queue<NodeDetails> q;

    int i=0;
    NodeDetails newNode;
    newNode.ptr = new Node(arr[i++]);
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);
    root = newNode.ptr;

    // using the method of level order traversal to construct BST
    // queue has been used to store the elements from array and construct BST
    while (i != n)
    {
        NodeDetails temp = q.front();
        q.pop();
        if (i < n && (arr[i] < temp.ptr->data && arr[i] > temp.min))
        {
            newNode.ptr = new Node(arr[i++]);
            newNode.min = temp.min;
            newNode.max = temp.ptr->data;
            q.push(newNode);
            temp.ptr->left = newNode.ptr;
        }
        if (i < n && (arr[i] > temp.ptr->data && arr[i] < temp.max))
        {
            newNode.ptr = new Node(arr[i++]);
            newNode.min = temp.ptr->data;
            newNode.max = temp.max;
            q.push(newNode);
            temp.ptr->right = newNode.ptr;
        }
    }
    return root;
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

int main() {
    int BST[] ={ 7, 4, 12, 3, 6, 8, 1, 5, 10 };

    Node *root=constructBst(BST, 9);



    inOrder(root);

}