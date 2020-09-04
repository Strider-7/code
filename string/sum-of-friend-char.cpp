#include <bits/stdc++.h>
using namespace std;

int total(string str)
{
    vector<pair<char, int>> v;
    for (int i = 0; i < str.length(); i++)
        v.push_back({str[i], i});
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j].first == v[i].first)
                res += abs(v[i].second - v[j].second);
            else
                break;
        }
    }

    return res;
}
int total2(string str)
{
    unordered_map<char, vector<int>> map;
    for (int i = 0; i < str.length(); i++)
        map[str[i]].push_back(i);
    int res = 0;
    for (auto &&i : map)
    {
        cout << i.first << " ";
        for (auto &&j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < str.length(); i++)
        for (auto &&j : map[str[i]])
            if (j > i)
                res += abs(i - j);

    return res;
}

int minimumDistance(string str)
{

    int n = str.length();
    map<char, int> hmap;

    int res = 0;
    ;

    int previousIndex = 0, currentIndex = 0;

    for (int i = 0; i < n; i++)
    {

        if (hmap.find(str[i]) != hmap.end())
        {
            currentIndex = i;

            previousIndex = hmap[str[i]];

            // Find the minimum distance.
            res += abs(currentIndex -
                       previousIndex);
        }

        // Update the map.
        hmap[str[i]] = i;
    }

    // return minimum distance,
    // if no such elements found, return -1
    return res;
}

int main()
{
    // cout << total("ababa");
    // cout << total2("ababa") << endl; 
    cout << minimumDistance("ababa");
    return 0;
}