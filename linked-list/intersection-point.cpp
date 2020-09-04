#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *head = nullptr, *last = nullptr;

int count(Node *node)
{
    int c = 0;
    while (node)
    {
        c++;
        node = node->next;
    }
    return c;
}

int intersection(Node *l1, Node *l2)
{
    unordered_set<Node *> s;
    while (l2)
    {
        s.insert(l2);
        l2 = l2->next;
    }
    while (l1)
    {
        if (s.find(l1) != s.end())
            return l1->data;
        l1 = l1->next;
    }
    return 0;
}

int intersection2(Node *l1, Node *l2)
{
    int c1 = count(l1);
    int c2 = count(l2);
    Node *p = c1 > c2 ? l1 : l2;
    Node *q = (p == l1) ? l2 : l1;
    for (int i = 0; i < abs(c1 - c2); i++)
        p = p->next;
    while (p && q)
    {
        if (p == q)
            return p->data;
        p = p->next;
        q = q->next;
    }
    return -1;
}


Node *getIntersectionNode(Node *headA, Node *headB) 
{
    Node *p1 = headA;
    Node *p2 = headB;
        
    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }
        
    return p1;
}