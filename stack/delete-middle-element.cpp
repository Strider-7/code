#include <bits/stdc++.h>

using namespace std;

stack<int> deleteMid(stack<int> s, int sizeOfStack, int current)
{
    if (current == sizeOfStack / 2)
    {
        s.pop();
        return s;
    }
    int x = s.top();
    s.pop();
    s = deleteMid(s, sizeOfStack, current+1);
    s.push(x);
    return s;
}

int main()
{
    stack<int> s;
    for (int i = 1; i <= 5; i++)
        s.push(i);

    s = deleteMid(s, s.size(), 0);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}