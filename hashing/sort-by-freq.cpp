#include <bits/stdc++.h>
using namespace std;

bool sortByVal(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

vector<int> sortByFreq2(int arr[], int n)
{
    unordered_map<int, int> m;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    copy(m.begin(), m.end(), back_inserter(v));

    sort(v.begin(), v.end(), sortByVal);
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].second; j++)
        {
            ans.push_back(v[i].first);
        }
    }
    m.clear();
    return ans;
}

vector<int> sortByFreq(int arr[], int n)
{
    sort(arr, arr + n, greater<int>());
    unordered_map<int, int> mp;
    multimap<int, int> mp2;
    vector<int> res;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            mp2.insert({mp[arr[i]], arr[i]});
            mp.erase(arr[i]);
        }
    }

    for (auto itr = mp2.rbegin(); itr != mp2.rend(); ++itr)
    {
        int c = itr->first;
        while (c)
        {
            res.push_back(itr->second);
            c--;
        }
    }
    return res;
}

int main()
{
    
    int arr1[] = {5, 5, 3, 6, 3, 4, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    vector<int> v = sortByFreq(arr1, n1);
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> v2 = sortByFreq2(arr1, n1);
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}