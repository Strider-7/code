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

bool detectLoop()
{
    unordered_set<Node *> s;
    for (Node *i = head; i != nullptr; i = i->next)
    {
        if (s.find(i) != s.end())
            return true;
        s.insert(i);
    }
    return false;
}

int main()
{
    vector<int> v = {5, 10, 15, 20, 25};
    for (auto &&i : v)
        create(i);

    display();

    
    createLoop();
    cout << loopExist() << endl;
    cout << detectLoop() << endl;

    return 0;
}