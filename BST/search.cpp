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

bool search(Node *root, int k) {
    if (!root)
        return false;

    if (root->data==k)
        return true;

    else if (k<root->data)
        return search(root->left, k);
    else
        return search(root->right, k);


}

bool search2(Node *root, int k)
{
    while (root)
    {
        if (root->data==k)
            return true;
        else if (k<root->data)
            root=root->left;
        else
            root=root->right;
    }

    return false;

}
int main()
{
    Node *root = new Node(100);
    root->left = new Node(60);
    root->right = new Node(120);
    root->right->left = new Node(110);
    root->right->right = new Node(130);
    root->left->left = new Node(50);
    root->left->right = new Node(70);

    cout<<search(root, 70)<<endl;
    cout<<search2(root, 70);



    return 0;
}
