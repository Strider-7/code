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

void buildVector(Node *root, vector<vector<int>> &ret, int depth)
{
    if (root == NULL)
        return;
    if (ret.size() == depth)
        ret.push_back(vector<int>());

    ret[depth].push_back(root->data);
    buildVector(root->left, ret, depth + 1);
    buildVector(root->right, ret, depth + 1);
}

vector<vector<int>> levelOrder2(Node *root)
{
    vector<vector<int>> ret;
    buildVector(root, ret, 0);
    return ret;
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        cout << node->data << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
        q.pop();
    }
}

void levelOrderLineByLine(Node *root)
{
    queue<Node *> q;
    if (root)
    {
        q.push(root);
        q.push(nullptr);
    }
    while (q.size() > 1)
    {
        Node *node = q.front();
        q.pop();
        if (node == nullptr)
        {
            cout << "\n";
            q.push(nullptr);
            continue;
        }
        cout << node->data << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

void levelOrderLineByLine2(Node *root)
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
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    levelOrder(root);
    cout << endl;
    levelOrderLineByLine(root);
    cout << endl;
    levelOrderLineByLine2(root);

    return 0;
}
