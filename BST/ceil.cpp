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

Node *f=nullptr;

Node * findCeil1(Node *root, int k) {
    if (!root)
        return nullptr;

    if (root->data==k)
    {
        f=root;
        return root;
    }

    else if (k>root->data)
        return findCeil1(root->right, k);

    else
    {
        f=root;
        return findCeil1(root->left, k);
    }
    return root;
}
Node * findCeil2(Node *root, int k) {
    Node *res=nullptr;
    while (root)
    {
        if (root->data==k)
            return root;
        else if (root->data>k)
        {
            res=root;
            root=root->left;
        }
        else
            root=root->right;


    }
    return res;

}

int findCeil(Node* root, int input)
{
    // Base case 
    if (root == NULL)
        return -1;

    // We found equal key 
    if (root->data == input)
        return root->data;

    // If root's key is smaller, ceil must be in right subtree 
    if (root->data < input)
        return findCeil(root->right, input);

    // Else, either left subtree or root has the ceil value 
    int cceil = findCeil(root->left, input);
    return (cceil >= input) ? cceil : root->data;


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

    findCeil(root, 55);

    cout<<f->data<<endl;
    cout<<findCeil2(root, 53)->data;




    return 0;
}