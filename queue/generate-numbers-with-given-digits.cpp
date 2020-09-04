#include <bits/stdc++.h>
using namespace std;

vector<int> generate(queue<int> &q, int n, int c = 0)
{
    if (c == n)
        return {};
    vector<int> res;
    res = generate(q, n, c + 1);
    int x = q.front();
    res.push_back(x);
    q.pop();

    q.push(x * 10 + 5);
    q.push(x * 10 + 6);

    return res;
}

vector<int> generateNumbers(vector<int> v, int n)
{
    sort(v.begin(), v.end());
    queue<string> q;
    for (auto &&i : v)
        q.push(to_string(i));

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        string s = q.front();
        q.pop();
        res.push_back(stoi(s));
        for (auto &&j : v)
            q.push(s + to_string(j));
    }
    return res;
}

void generateNumbers(int n)
{
    queue<string> q;
    q.push("5");
    q.push("6");

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        string s = q.front();
        q.pop();
        cout << s << " ";

        q.push(s + "5");
        q.push(s + "6");
    }
}

int main()
{
    vector<int> v = {5, 6};
    v = generateNumbers(v, 10);

    // generateNumbers(10);
    queue<int> q;
    q.push(5);
    q.push(6);

    v = generate(q, 10);

    for (auto &&i : v)
        cout << i << " ";

    return 0;
}