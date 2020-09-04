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

void pairwiseSwap()
{
    if (!head || !head->next)
        return;
    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;
    while (curr && curr->next)
    {
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
}

Node *swapPairs(Node *head)
{
    //base case here
    if (!head || !head->next)
        return head;
    //Swapping part happens here, please draw to visualize
    Node *temp = head->next;
    head->next = swapPairs(temp->next);
    temp->next = head;

    return temp;
}

int main()
{
    vector<int> v = {5, 10, 15, 20, 25};
    for (auto &&i : v)
        create(i);

    display();
    // pairwiseSwap();
    head = swapPairs(head);
    display();

    return 0;
}