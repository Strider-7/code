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

Node *insert(Node *root, int data) {
    if (!root)
        return new Node(data);

    if (data==root->data)
        return nullptr;

    else if (data<root->data)
        root->left=insert(root->left, data);

    else
        root->right=insert(root->right, data);

    return root;

}

void inOrder(Node *root, unordered_set <int> &s) {
    if (root)
    {
        inOrder(root->left, s);
        s.insert(root->data);
        inOrder(root->right, s);
    }

}

bool  findPair(vector <int> arr, int k)
{
    int low = 0, high = arr.size()- 1;
    while (low < high)
    {
        if (k == arr[low] + arr[high])
            return true;
        if (arr[low] + arr[high] > k)
            high--;
        else
            low++;
    }
    return false;
}

bool pairExists(Node *root, int sum) {
    if (!root)
        return false;

    unordered_set <int> s;
    inOrder(root, s);
    for (auto &&i : s)
    {
        auto itr=s.find(sum-i);
        if (itr!=s.end() && *itr!=i)
            return true;

    }
    return false;

}

bool pairWithSum(Node *root, int sum, unordered_set <int> &s) {
    if (!root)
        return false;
    if (pairWithSum(root->left, sum, s))
        return true;
    if (s.find(sum-root->data)!=s.end())
        return true;
    else
        s.insert(root->data);

    return pairWithSum(root->right, sum, s);
}




int main() {

    Node *root=nullptr;

    root=insert(root, 40);
    root=insert(root, 30);
    root=insert(root, 60);
    root=insert(root, 50);
    root=insert(root, 70);
    root=insert(root, 20);
    root=insert(root, 10);

    cout<<pairExists(root, 20)<<endl;
    unordered_set <int> s;
    cout<<pairWithSum(root, 20, s);









    return 0;
}