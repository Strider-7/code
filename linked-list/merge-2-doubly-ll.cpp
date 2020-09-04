#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node *next, *prev;
};

Node* merge( Node* a, Node* b)
{
	// Base cases
	if (!a)
		return b;

	if (!b)
		return a;

	if (a->data <= b->data)
	{
		a->next = merge(a->next, b);
		a->next->prev = a;
		a->prev = NULL;
		return a;
	}
	else
	{
		b->next = merge(a, b->next);
		b->next->prev = b;
		b->prev = NULL;
		return b;
	}
}