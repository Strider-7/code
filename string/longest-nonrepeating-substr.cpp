#include <bits/stdc++.h>
using namespace std;
int length(string str)
{
    int res = 0;
    unordered_map<char, int> mp;
    int low = 0;
    for (int i = 0; i < str.length(); i++)
    {

        while (mp[str[i]] != 0)
        {

            mp.erase(str[low]);
            low++;
        }

        mp[str[i]]++;
        int size = mp.size();
        res = max(res, size);
    }
    return res;
}

int main()
{
    cout << length("abcdabc");

    return 0;
}