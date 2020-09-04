#include <iostream>
#include <vector>
#include <unordered_set>

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

void createLoop()
{

    Node *node = head;
    while (node->next)
        node = node->next;
    node->next = head->next;
}

bool loopExist()
{
    Node *p, *q;
    p = q = head;
    while (q && q->next)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
            return true;
    }
    return false;
}

void detectAndRemoveLoop()
{
    unordered_set<Node *> s;
    for (Node *i = head; i != nullptr; i = i->next)
    {
        if (s.find(i->next) != s.end())
        {
            i->next = nullptr;
            break;
        }
        s.insert(i);
    }
}

void removeLoop()
{
    Node *p, *q;
    p = q = head;
    while (q && q->next)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
            break;
    }
    if (p != q)
        return;
    while (p->next != q->next)
    {
        p = p->next;
        q = q->next;
    }
    q->next = nullptr;
}

void removeLoop2(Node *node)
{
    if (node == NULL || node->next == NULL)
        return;

    Node *slow = node, *fast = node;

    slow = slow->next;
    fast = fast->next->next;

    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow == fast)
    {
        slow = node;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = NULL;
    }
}

int main()
{
    vector<int> v = {7, 58, 36, 34, 16};
    for (auto &&i : v)
        create(i);

    display();

    createLoop();
    cout << loopExist() << endl;
    // detectAndRemoveLoop();
    // removeLoop();
    removeLoop2(head);
    cout << loopExist() << endl;

    return 0;
}