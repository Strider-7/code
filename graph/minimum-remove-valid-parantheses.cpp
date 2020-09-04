#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string str)
{
    int count = 0;
    for (auto i : str)
    {
        if (i == '(')
            count++;
        else if (i == ')')
            count--;
        if (count < 0)
            return false;
    }
    return count==0;
}
string minRemoveToMakeValid(string s)
{
    queue<string> q;
    q.push(s);
    unordered_map<string, bool> visited;
    while (!q.empty())
    {
        string u = q.front();
        q.pop();
        if (visited.find(u)!=visited.end())
            continue;
        visited[u]=true;
        if (isBalanced(u))
            return u;
        for (int i = 0; i < u.length(); i++)
        {
            string temp = u.substr(0, i) + u.substr(i + 1, u.length());
            q.push(temp);
        }
    }
    return "";
}

int main()
{
    string str = "())fwk)))())(())))())()()((())";
    cout << minRemoveToMakeValid(str)<<endl;
    // cout<<isBalanced("(a(b(c)d)");
    return 0;
}