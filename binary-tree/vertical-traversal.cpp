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

vector <vector<int>> verticalTraversal(Node *root) {
    map <int, vector <int>> map;
    queue <pair<Node *, int>> q;

    q.push({ root, 0 });
    while (!q.empty())
    {
        auto p=q.front();
        Node *curr=p.first;
        int hd=p.second;
        map[hd].push_back(curr->data);
        q.pop();
        if (curr->left)
            q.push({ curr->left, hd-1 });
        if (curr->right)
            q.push({ curr->right, hd+1 });


    }
    vector <vector<int>> res;
    for (auto &&i : map)
        res.push_back(i.second);

    return res;

}

vector<vector<int>> verticalTraversal(Node* root) {
    map<int, map<int, set<int>>> nodes;
    traverse(root, 0, 0, nodes);
    vector<vector<int>> ans;
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

void traverse(Node* root, int x, int y, map<int, map<int, set<int>>>& nodes) {
    if (root) {
        nodes[x][y].insert(root->data);
        traverse(root->left, x - 1, y + 1, nodes);
        traverse(root->right, x + 1, y + 1, nodes);
    }
}



int main() {

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    root->left->left = new Node(40);
    root->left->right = new Node(50);


    vector <vector<int>> v=verticalTraversal(root);

    for (auto &&i : v)
    {
        for (auto &&j : i)
            cout<<j<<" ";
        cout<<endl;
    }










    return 0;
}