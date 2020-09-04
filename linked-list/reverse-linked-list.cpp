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

void reverse()
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
    head = q;
}

void reverseListRec(Node *p, Node *q)
{
    if (p)
    {

        reverseListRec(p->next, p);
        p->next = q;
    }
    else
    {
        head = q;
        return;
    }
}

Node *reverseList(Node *node)
{
    if (!node || !node->next)
        return node;
    Node *newHead = reverseList(node->next);
    node->next->next = node;
    node->next=nullptr;
    return newHead;
}

int main()
{
    vector<int> v = {5, 10, 15, 20, 25, 52, 60};
    for (auto &&i : v)
        create(i);

    // display();
    // reverse();
    // reverseListRec(head, nullptr);
    head = reverseList(head);
    display();

    return 0;
}