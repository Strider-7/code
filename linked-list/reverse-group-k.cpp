#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *create(Node *head, Node **last, int data)
{ 
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    if (!head)
        head = *last = new_node;
    else
    {
        (*last)->next = new_node;
        *last = new_node;
    }
    return head;
}

void display(Node *head)
{
    Node *node = head;
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node *reverseGroupK(Node *head, int k)
{
    Node *curr = head;
    Node *prev = nullptr, *next = nullptr;
    int count = 0;
    while (curr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next)
    {
        Node *tempHead = reverseGroupK(next, k);
        head->next = tempHead;
    }
    return prev;
}

int main()
{
    Node *head = nullptr, *last = nullptr;
    vector<int> v = {1,2,3,4,5};
    for (auto &&i : v)
        head = create(head, &last, i);

    display(head);

    head = reverseGroupK(head, 3);

    display(head);

    return 0;
}  