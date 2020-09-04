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

void preOrderIterative(Node *root)
{
    stack<Node *> st;
    Node *p = root;
    while (p || !st.empty())
    {
        if (p)
        {
            cout << p->data << " ";
            st.push(p);

            p = p->left;
        }

        else
        {
            p = st.top();
            st.pop();
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

    preOrder(root);
    cout<<endl;
    preOrderIterative(root);

    return 0;
}
