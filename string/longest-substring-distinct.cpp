#include <bits/stdc++.h>
using namespace std;

bool areDistinct(string str, int i, int j)
{
    bool visited[256]{};
    for (int c = i; c <= j; c++)
    {
        if (visited[str[c]])
            return false;
        visited[str[c]] = true;
    }
    return true;
}

int length(string s)
{
    int n = s.length();
    if (n == 0 || n == 1)
        return n;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(256);

        for (int j = i; j < n; j++)
        {
            if (visited[s[j]] == true)
                break;
            else
            {
                res = max(res, j - i + 1);
                visited[s[j]] = true;
            }
        }
        visited[s[i]] = false;
    }
    return res;
}

int longestDistinctSubstr(string str)
{
    bool exist[200] = {false};
    int n = str.length();
    int left = 0, right = 0; /* window between left and right */
    int maxLen = 0;
    while (right < n)
    {
        if (exist[str[right]])
        {                                       //exist array index having true
            maxLen = max(maxLen, right - left); /* windowsize */
            while (str[left] != str[right])
            {
                exist[str[left]] = false; /* decreasing size of substr */
                left++;
            }
            left++;
            right++;
        }
        else
        { //false
            exist[str[right]] = true;
            right++; /* increasing size of substr */
        }
    }
    maxLen = max(maxLen, n - left);
    return maxLen;
}

int longestDistinct(string str)
{
    int n = str.length(), res = 0;
    vector<int> prev(256, -1);
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, prev[str[j]] + 1);
        int maxEnd = j - i + 1;
        res = max(res, maxEnd);
        prev[str[j]] = j;
    }
    return res;
}

int main()
{
    string s = "abac";
    cout << length(s) << endl;
    cout << longestDistinctSubstr(s) << endl;
    cout << longestDistinct(s) << endl;

    return 0;
}