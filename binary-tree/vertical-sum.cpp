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



void findSum(Node *root, unordered_map <int, int> &map, int hd)
{
    if (!root)
        return;
    map[hd]+=root->data;
    findSum(root->left, map, hd-1);
    findSum(root->right, map, hd+1);

}

vector <int> verticalSum(Node *root) {
    unordered_map <int, int> map;

    findSum(root, map, 0);
    int n=map.size();
    vector <int> res(n);
    for (auto &&i : map)
        res[i.first+n/2]=i.second;

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


    vector <int> v=verticalSum(root);

    for (auto &&i : v)
    {
        cout<<i<<" ";
    }









    return 0;
}