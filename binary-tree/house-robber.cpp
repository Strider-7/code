// Input: [3,2,3,null,3,null,1]

//      3
//     / /
//    2   3
//     \   \ 
//      3   1

// Output: 7 
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
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

int rob(Node* root) {
    queue<Node *> q;

    if (root)
        q.push(root);
    int oddSum1=root->data, oddSum2=0, evenSum=0, depth=-1, firstOdd=1;
    while (!q.empty())
    {
        depth++;
        int count = q.size();
        // cout<<"count="<<count<<endl;
        for (int i = 0; i < count; i++)
        {
            Node *node = q.front();
            q.pop();
            if (depth%2==0)
                evenSum+=node->data;
            else {
                if (firstOdd)
                    oddSum2+=root->data;
                else
                {
                    oddSum1+=root->data;
                    oddSum2+=root->data;
                }
            }

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout<<oddSum1<<endl;
        cout<<oddSum2<<endl;
        if (depth==1) firstOdd=0;

    }
    cout<<oddSum1<<endl;
    cout<<oddSum2<<endl;
    return max({ oddSum1, oddSum2, evenSum });
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

    cout<<rob(root);

    return 0;
}