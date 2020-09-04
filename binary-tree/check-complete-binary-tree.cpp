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

bool isCompleteTree(Node* root) {
    queue<Node *> q;
    if (root)
        q.push(root);
    bool prev=true;
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *node = q.front();
            q.pop();

            if (node==nullptr)
                prev=false;
            else
            {
                if (prev==false)
                    return false;
                q.push(node->left);
                q.push(node->right);
            }


        }
    }
    return true;

}


int main() {

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout<<isCompleteTree(root);




    return 0;
}