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

int count(Node *node)
{
    int count = 0;
    while (node)
    {
        count++;
        node = node->next;
    }
    return count;
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

    // Advance 'fast' two nodes, and advance 'slow' one node
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is before the midpoint in the list, so split it in two
    // at that point.
    frontRef = source;
    backRef = slow->next;
    slow->next = NULL;
    return make_pair(frontRef, backRef);
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;

    pair<Node *, Node *> P = FrontBackSplit(head);
    Node *p = P.first, *q = P.second;
    p = mergeSort(p);
    q = mergeSort(q);

    head = mergeTwoLists(p, q);
    return head;
}

int main()
{
    Node *head = nullptr, *last = nullptr;
    vector<int> v = {5, 10, 8, 9, 7, 6, 3, 2, 1};
    for (auto &&i : v)
        head = create(head, &last, i);

    display(head);

    head = mergeSort(head);

    display(head);

    return 0;
}