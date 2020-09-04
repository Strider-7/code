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

Node *sortedMerge(Node *a, Node *b)
{
    if (a == nullptr)
        return b;

    else if (b == nullptr)
        return a;

    Node *result;

    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

Node *mergeKLists(vector<Node *> &list)
{

    if (list.empty())
        return nullptr;
    int last = list.size() - 1;

    while (last != 0)
    {
        
        int i = 0, j = last;
        while (i < j)
        {
            list[i] = sortedMerge(list[i], list[j]);
            i++, j--;
            if (i >= j)
                last = j;
        }
    }

    return list[0];
}