#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *head = nullptr, *last = nullptr;

Node *removeDuplicates(Node *head)
{
    unordered_set<int> seen;

    struct Node *curr = head;
    struct Node *prev = nullptr;
    while (curr)
    {
        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}