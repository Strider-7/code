#include <iostream>
#include <vector>

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

void segregate()
{
    Node *node = head;
    Node *headOdd = nullptr, *tailOdd = nullptr, *headEven = nullptr, *tailEven = nullptr;
    while (node)
    {
        if (node->data % 2 == 1)
        {
            if (!headOdd)
            {
                headOdd = node;
                tailOdd = node;
            }
            else
            {
                tailOdd->next = node;
                tailOdd = node;
            }
        }
        else
        {
            if (!headEven)
            {
                headEven = node;
                tailEven = node;
            }
            else
            {
                tailEven->next = node;
                tailEven = node;
            }
        }
        node = node->next;
    }
    tailEven->next = headOdd;
    tailOdd->next = nullptr;
    head = headEven;
}

void segregate2()
{
    Node *end = head;
    Node *prev = NULL;
    Node *curr = head;

    /* Get pointer to the last node */
    while (end->next != NULL)
        end = end->next;

    Node *new_end = end;

    /* Consider all odd nodes before the first  
     even node and move then after end */
    while (curr->data % 2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }

    // 10->8->17->17->15
    /* Do following steps only if  
    there is any even node */
    if (curr->data % 2 == 0)
    {
        /* Change the head pointer to  
        point to first even node */
        head = curr;

        /* now current points to 
        the first even node */
        while (curr != end)
        {
            if ((curr->data) % 2 == 0)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                /* break the link between 
                prev and current */
                prev->next = curr->next;

                /* Make next of curr as NULL */
                curr->next = NULL;

                /* Move curr to end */
                new_end->next = curr;

                /* make curr as new end of list */
                new_end = curr;

                /* Update current pointer to 
                next of the moved node */
                curr = prev->next;
            }
        }
    }

    /* We must have prev set before executing  
    lines following this statement */
    else
        prev = curr;

    /* If there are more than 1 odd nodes  
    and end of original list is odd then  
    move this node to end to maintain  
    same order of odd numbers in modified list */
    if (new_end != end && (end->data) % 2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}

int main()
{
    vector<int> v = {5, 10, 15, 20, 25};
    for (auto &&i : v)
        create(i);

    display();
    segregate2();
    display();
}