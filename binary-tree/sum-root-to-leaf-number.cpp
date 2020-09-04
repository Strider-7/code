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

void fillPath(Node *root, vector <string> &v, string curr) {
    if (!root)
    {
        v.push_back(curr);
        return;
    }
    int x=root->data;
    fillPath(root->left, v, curr +to_string(x));
    fillPath(root->right, v, curr+to_string(x));
}
int sumNumbers(Node* root) {
    int res=0;
    vector <string> v;
    fillPath(root, v, "");
    for (auto i:v)
        cout<<i<<" ";
    return res;
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

    sumNumbers(root);

    return 0;
}
