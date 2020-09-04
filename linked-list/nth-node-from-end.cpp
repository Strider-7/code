#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *head = nullptr, *last = nullptr;

void create(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
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

int count()
{
    Node *node = head;
    int c = 0;
    while (node)
    {
        c++;
        node = node->next;
    }
    return c;
}

Node *nthNodeFromEnd(int n)
{
    Node *node = head;
    int c = count();
    if (n > c)
        return nullptr;
    for (int i = 0; i < c - n; i++)
        node = node->next;
    return node;
}

int NthNodeEnd(int n)
{
    Node *p = head;
    Node *q = head;
    for (int i = 0; i < n; i++)
    {
        if (!p)
            return -1;
        p = p->next;
    }

    while (p)
    {
        p = p->next;
        q = q->next;
    }
    return q->data;
}

int main()
{
    vector<int> v = {5, 10, 15, 20, 25, 52, 60};
    for (auto &&i : v)
        create(i);

    display();

    // Node *node = nthNodeFromEnd(3);
    // cout << node->data << endl;

    cout << NthNodeEnd(3);

    return 0;
}