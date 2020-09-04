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


void serialize(Node *root, vector <int> &v) {
    if (!root)
    {
        v.push_back(-1);
        return;
    }
    v.push_back(root->data);
    serialize(root->left, v);
    serialize(root->right, v);
}
int i=0;
Node * deserialize(vector <int> &v) {
    if (i==v.size()) return nullptr;
    int x=v[i];
    i++;
    if (x==-1)
        return nullptr;

    Node *node=new Node(x);
    node->left=deserialize(v);
    node->right=deserialize(v);
    return node;

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

    vector <int> v;

    serialize(root, v);

    for (auto &&i : v)
        cout<<i<<" ";

    cout<<endl;

    Node *p=deserialize(v);

    preOrder(p);


    return 0;
}
