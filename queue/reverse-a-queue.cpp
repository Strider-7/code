#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

queue<int> rev(queue<int> q)
{
    if (q.empty())
        return q;

    // Dequeue current item (from front)
    int data = q.front();
    q.pop();

    // Reverse remaining queue
    q = rev(q);

    // Enqueue current item (to rear)
    q.push(data);

    return q;
}

int main()
{

    vector<int> v = {10, 15, 20, 25, 30};

    queue<int> q(deque<int>(v.begin(), v.end()));

    // reverseQueue(q);
    q = rev(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}