#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *head = nullptr, *last = nullptr;


Node *removeDuplicates(Node *root)
{
    Node *p = root;
    Node *q = p->next;
    while (q)
    {

        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {

            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
    return root;
}

