#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
} *head = nullptr, *last = nullptr;

void create(int data)
{
    Node *new_node = new Node(data);
    if (!head)
        head = last = new_node;
    else
    {
        last->next = new_node;
        last = new_node;
    }
}

void display()
{
    Node *node = head;
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node *reverse(Node *head)
{
    Node *p = head;
    Node *q = nullptr;
    Node *r = nullptr;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

Node *addTwoLists(struct Node *X, struct Node *Y)
{
    X = reverse(X);
    Y = reverse(Y);

    Node *prevNode = nullptr, *newHead = nullptr;

    int carry = 0;

    while (X || Y)
    {
        int sum = 0;
        if (X)
            sum += X->data;
        if (Y)
            sum += Y->data;
        sum += carry;

        carry = sum / 10;
        sum = sum % 10;

        Node *node = new Node(sum);
        if (!newHead)
        {
            prevNode = node;
            newHead = node;
        }
        else
        {
            prevNode->next = node;
            prevNode = node;
        }
        if (X)
            X = X->next;

        if (Y)
            Y = Y->next;
    }

    if (carry)
    {
        Node *node = new Node(carry);
        prevNode->next = node;
    }

    newHead = reverse(newHead);

    return newHead;
}