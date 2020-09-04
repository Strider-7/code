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
Node *f=nullptr;

Node * findFloor(Node *root, int k) {
    if (!root)
        return nullptr;

    if (root->data==k)
        {   
            f=root;
            return root;
        }

    else if (k<root->data)
     return findFloor(root->left, k);
    
    else
    {   
        f=root;
        return findFloor(root->right, k);
    }
    return root;
}
Node * findFloor2(Node *root, int k) {
    Node *res=nullptr;
    while (root)
    {
        if(root->data==k)
            return root;
        else if(root->data>k)
            root=root->left;
        else
        {
            res=root;
            root=root->right;
        }
    
    }
    return res;
    
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

    findFloor(root, 63);

    cout<<f->data<<endl;
    cout<<findFloor2(root,63)->data;




    return 0;
}