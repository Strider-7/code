#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    vector<int> v;
    int n = q.size();
    for (int i = 0; i < k; i++)
    {
        v.push_back(q.front());
        q.pop();
    }
    for (int i = 0; i < k; i++)
    {
        q.push(v.back());
        v.pop_back();
    }

    for (int i = k; i < n; i++)
    {
        v.push_back(q.front());
        q.pop();
    }

    for (int i = 0; i < v.size(); i++)
        q.push(v[i]);

    return q;
}

int main()
{

    vector<int> v = {10, 15, 20, 25, 30};

    queue<int> q(deque<int>(v.begin(), v.end()));

    q = modifyQueue(q, 3);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}