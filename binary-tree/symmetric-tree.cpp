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

bool isSymmetric(Node* p, Node *q) {
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;

    return (p->data == q->data) && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);

}

bool check(Node* left_node, Node* right_node) {
    if (left_node == nullptr && right_node == nullptr)
        return true;

    else if (left_node != nullptr && right_node != nullptr)
    {
        return left_node->data == right_node->data &&
            check(left_node->left, right_node->right) &&
            check(left_node->right, right_node->left);
    }

    return false;
}
bool isSymmetric(Node* root) {
    return root == nullptr || check(root->left, root->right);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(50);
    root->right->right = new Node(40);

    queue <int> q;
    

    cout<<isSymmetric(root->left, root->right)<<endl;
    cout<<isSymmetric(root);


    return 0;
}
