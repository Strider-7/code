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

void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void inOrderIterative(Node *root)
{
    stack<Node *> st;
    Node *p = root;
    while (p || !st.empty())
    {
        if (p)
        {

            st.push(p);
            p = p->left;
        }

        else
        {
            p = st.top();
            st.pop();
            cout << p->data << " ";
            p = p->right;
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    inOrder(root);
    cout << endl;
    inOrderIterative(root);

    return 0;
}
