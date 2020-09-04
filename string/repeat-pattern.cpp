#include <bits/stdc++.h>

using namespace std;

bool repeatedSubstringPattern(string s)
{
    string curr = "";
    for (int i = 0; i < s.length()/2; i++)
    {
        curr += s[i];
        if (s.length() % curr.length() == 0)
        {
            string str = curr, temp = curr;
            int x = curr.length();
            for (int j = 1; j < s.length() / x; j++)
                temp += str;
            cout << temp << endl;
            if (temp == s)
                return true;
        }
    }
    return false;
}

int main()
{
    cout << repeatedSubstringPattern("ababab");
    return 0;
}