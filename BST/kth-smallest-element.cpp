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
int res=0,c=0;
void kthSmallestElement(Node *root,int k){
    if(!root)
        return;
    kthSmallestElement(root->left,k);
    c++; if(c==k) {res=root->data;return;}
    kthSmallestElement(root->right,k);
}


int main() {
    Node *root=nullptr;
    root=insert(root, 5);
    for (int i=0;i<5;i++)
        root=insert(root, i);
    for (int i=6;i<10;i++)
        root=insert(root, i);

    kthSmallestElement(root,5);
    cout<<res;
    


    return 0;
}