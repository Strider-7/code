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

bool isIdentical(Node* T, Node* S) {
    if (!T && !S)
        return true;
    if (!T || !S)
        return false;
    return T->data == S->data && isIdentical(T->left, S->left) && isIdentical(T->right, S->right);
}
bool isSubTree(Node* T, Node* S) {

    if (!S)
        return true;
    if (!T)
        return false;

    if (isIdentical(T, S))
        return true;


    return isSubTree(T->left, S) || isSubTree(T->right, S);
}