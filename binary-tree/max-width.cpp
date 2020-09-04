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

int maxWidth(Node *root)
{
    int res = 0;
    queue<Node *> q;
    if (root)
        q.push(root);
    else
        return 0;
    while (!q.empty())
    {

        int count = q.size();
        res = max(res, count);
        for (int i = 0; i < count; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        
    }
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

    cout << maxWidth(root);

    return 0;
}
