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

Node *createBST(vector <int> &v, int low, int high) {
    if (low>high)
        return nullptr;
    int mid=(low+high)/2;
    Node *root= new Node(v[mid]);
    root->left=createBST(v, low, mid-1);
    root->right=createBST(v, mid+1, high);
    return root;

}

void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    vector <int> BST ={ 7, 4, 12, 3, 6, 8, 1, 5, 10 };

    Node *root=createBST(BST, 0, BST.size()-1);



    inOrder(root);

}