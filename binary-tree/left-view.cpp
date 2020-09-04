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

int maxLevel = 0;

void printLeftView(Node *root, int level)
{
    if (!root)
        return;
    if (maxLevel < level)
    {
        cout << root->data << " ";
        maxLevel = level;
    }
    printLeftView(root->left, level + 1);
    printLeftView(root->right, level + 1);
}

void leftView(Node *root)
{
    printLeftView(root, 1);
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *node = q.front();
            q.pop();
            if (i == 0)
                cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << endl;
    }
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

    leftView(root);
    levelOrder(root);

    return 0;
}
