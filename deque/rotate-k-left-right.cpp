#include <bits/stdc++.h>

using namespace std;

void left_Rotate_Deq_ByK(deque<int> &deq, int n, int k)
{
    
    k = n - (k % n);
    for (int i = 1; i <= k; i++)
    {
        int val = deq.back();
        deq.pop_back();
        deq.push_front(val);
    }
}

void right_Rotate_Deq_ByK(deque<int> &deq, int n, int k)
{
    k = k % n;
    for (int i = 1; i <= k; i++)
    {
        int val = deq.back();
        deq.pop_back();
        deq.push_front(val);
    }
}

void eraseAt(deque <int> &deq, int x)
{
    auto itr=deq.begin();
    for(int i=0;i<x;i++)
        itr++;
    deq.erase(itr);
    
}