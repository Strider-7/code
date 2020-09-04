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

vector<int> verticalTraversal(Node *root) {
    map <int, int> map;
    queue <pair<Node *, int>> q;

    q.push({ root, 0 });
    while (!q.empty())
    {
        auto p=q.front();
        Node *curr=p.first;
        int hd=p.second;
        map[hd]=curr->data;
        q.pop();
        if (curr->left)
            q.push({ curr->left, hd-1 });
        if (curr->right)
            q.push({ curr->right, hd+1 });


    }
    vector<int> res;
    for (auto &&i : map)
        res.push_back(i.second);

    return res;

}



int main() {

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    root->left->left = new Node(40);
    root->left->right = new Node(50);


    vector<int> v=verticalTraversal(root);

    for (auto &&i : v)
        cout<<i<<" ";

    return 0;
}