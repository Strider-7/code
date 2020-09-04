#include <bits/stdc++.h>
using namespace std;

bool checkAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;
}

bool anagram(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    unordered_map<char, int> map;

    for (auto &&i : str1)
        map[i]++;

    for (auto &&i : str2)
    {
        if (map.find(i) == map.end())
            return false;
        else
        {
            map[i]--;
            if (map[i] == 0)
                map.erase(i);
        }
    }
    for (auto &&i : map)
    {
        cout << i.first << " " << i.second << endl;
    }

    return map.empty();
}

bool anagramCheck(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    int count[256]{};
    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}

int main()
{

    string s1 = "geeksforgeeks", s2 = "forgeeksgeeks";
    cout << anagram(s1, s2) << endl;
    cout << checkAnagram(s1, s2) << endl;
    cout << anagramCheck(s1, s2);
    return 0;
}