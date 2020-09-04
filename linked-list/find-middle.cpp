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

int findMiddle()
{
    Node *p = head;
    Node *q = p;
    while (p && p->next)
    {
        p = p->next->next;
        q = q->next;
    }
    return q->data;
}

int main()
{
    vector<int> v = {5, 10, 15, 20, 25};
    for (auto &&i : v)
        create(i);

    display();

    cout << findMiddle();

    return 0;
}