#include <bits/stdc++.h>

using namespace std;

vector<int> prevGreater(vector<int> v)
{
    vector<int> res;
    stack<int> s;
    s.push(v[0]);
    res.push_back(-1);
    for (int i = 1; i < v.size(); i++)
    {
        while (!s.empty() && s.top() <= v[i])
            s.pop();
        int temp = s.empty() ? -1 : s.top();
        res.push_back(temp);
        s.push(v[i]);
    }
    return res;
}

int main()
{
    vector<int> v = {15, 10, 18, 12, 4, 6, 2, 8};

    v = prevGreater(v);

    for (auto &&i : v)
        cout << i << " ";

    return 0;
}