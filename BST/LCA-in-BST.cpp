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


Node* LCA(Node *root, int n1, int n2)
{
   if (!root) return nullptr;  
   
    if (root->data > n1 && root->data > n2)  
        return LCA(root->left, n1, n2);  
  
    if (root->data < n1 && root->data < n2)  
        return LCA(root->right, n1, n2);  
  
    return root;
}


int main() {
    Node *root = new Node(100);
    root->left = new Node(60);
    root->right = new Node(120);
    root->right->left = new Node(110);
    root->right->right = new Node(130);
    root->left->left = new Node(50);
    root->left->right = new Node(70);

    cout<<LCA(root,50,70)->data;

    


    return 0;
}

