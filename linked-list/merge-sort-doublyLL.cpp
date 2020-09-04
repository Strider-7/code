#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
};

Node *merge(Node *a, Node *b)
{
    // Base cases
    if (!a)
        return b;

    if (!b)
        return a;

    if (a->data <= b->data)
    {
        a->next = merge(a->next, b);
        a->next->prev = a;
        a->prev = NULL;
        return a;
    }
    else
    {
        b->next = merge(a, b->next);
        b->next->prev = b;
        b->prev = NULL;
        return b;
    }
}

pair<Node *, Node *> FrontBackSplit(Node *source)
{
    Node *frontRef = nullptr, *backRef = nullptr;
    if (source == nullptr || source->next == nullptr)
    {
        frontRef = source;
        backRef = nullptr;
        return make_pair(frontRef, backRef);
    }

    struct Node *slow = source;
    struct Node *fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    frontRef = source;
    backRef = slow->next;
    slow->next = NULL;
    return make_pair(frontRef, backRef);
}

struct Node *sortDoubly(struct Node *head)
{
    if (!head || !head->next)
        return head;

    pair<Node *, Node *> P = FrontBackSplit(head);
    Node *p = P.first, *q = P.second;
    p = sortDoubly(p);
    q = sortDoubly(q);

    head = merge(p, q);
    return head;
}