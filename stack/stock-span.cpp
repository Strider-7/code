#include <bits/stdc++.h>

using namespace std;

vector<int> stockSpan(vector<int> v)
{
    vector<int> res;
    stack<int> s;
    s.push(0);
    res.push_back(1);
    for (int i = 1; i < v.size(); i++)
    {
        while (!s.empty() && v[s.top()] <= v[i])
            s.pop();
        int span = s.empty() ? i + 1 : i - s.top();
        res.push_back(span);
        s.push(i);
    }
    return res;
}

int main()
{
    vector<int> v = {15, 13, 12, 14, 16, 8, 6, 4, 10, 30};
    v = stockSpan(v);
    for (auto &&i : v)
        cout << i << " ";

    return 0;
}