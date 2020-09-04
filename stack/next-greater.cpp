#include <bits/stdc++.h>

using namespace std;

vector<int> nexTGreater(vector<int> v)
{
    vector<int> res;
    stack<int> s;
    int n = v.size();
    s.push(v[n - 1]);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= v[i])
            s.pop();
        int temp = s.empty() ? -1 : s.top();
        res.push_back(temp);
        s.push(v[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> v = {15, 10, 18, 12, 4, 6, 2, 8};
 
    v = nexTGreater(v);

    for (auto &&i : v)
        cout << i << " ";

    return 0;
}