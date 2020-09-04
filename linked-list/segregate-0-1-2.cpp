#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *head = nullptr, *last = nullptr;

Node *segregate(Node *head)
{

    Node *node = head;
    Node *head0 = nullptr, *tail0 = nullptr, *head1 = nullptr;
    Node *tail1 = nullptr, *head2 = nullptr, *tail2 = nullptr;
    while (node)
    {
        if (node->data == 0)
        {
            if (!head0)
            {
                head0 = node;
                tail0 = node;
            }
            else
            {
                tail0->next = node;
                tail0 = node;
            }
        }
        else if (node->data == 1)
        {
            if (!head1)
            {
                head1 = node;
                tail1 = node;
            }
            else
            {
                tail1->next = node;
                tail1 = node;
            }
        }
        else
        {
            if (!head2)
            {
                head2 = node;
                tail2 = node;
            }
            else
            {
                tail2->next = node;
                tail2 = node;
            }
        }
        node = node->next;
    }
    if (tail0)
        tail0->next = head1 ? head1 : head2;
    if (tail1)
        tail1->next = head2;
    if (tail2)
        tail2->next = nullptr;

    if (head0)
        head = head0;
    else if (head1)
        head = head1;
    else
        head = head2;

    return head;
}
