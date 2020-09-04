#include <bits/stdc++.h>

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
};

Node *create(Node *head, Node **last, int data)
{
    Node *new_node = new Node(data);
    if (!head)
        head = *last = new_node;
    else
    {
        (*last)->next = new_node;
        *last = new_node;
    }
    return head;
}

void display(Node *node)
{
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node *mergeTwoLists1(Node *l1, Node *l2)
{

    Node *newHead = nullptr, *newTail = nullptr;
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->data < l2->data)
    {
        newHead = l1;
        newTail = l1;
        l1 = l1->next;
    }
    else
    {
        newHead = l2;
        newTail = l2;
        l2 = l2->next;
    }
    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            newTail->next = l1;
            newTail = l1;
            l1 = l1->next;
        }
        else
        {
            newTail->next = l2;
            newTail = l2;
            l2 = l2->next;
        }
    }

    if (l1)
        newTail->next = l1;
    else
        newTail->next = l2;

    return newHead;
}

Node *mergeTwoLists(Node *l1, Node *l2)
{

    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->data < l2->data)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

int main()
{
    Node *head1 = nullptr, *last1 = nullptr, *head2 = nullptr, *last2 = nullptr;
    vector<int> v1 = {1, 3};
    for (auto &&i : v1)
        head1 = create(head1, &last1, i);
    display(head1);

    vector<int> v2 = {2, 4, 6, 8};
    for (auto &&i : v2)
        head2 = create(head2, &last2, i);
    display(head2);

    head1 = mergeTwoLists1(head1, head2);

    display(head1);

    return 0;
}
