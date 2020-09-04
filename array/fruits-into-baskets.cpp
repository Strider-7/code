#include <bits/stdc++.h>
using namespace std;

int findMaxFruits(vector<char> &v)
{
    int maxLength = 0;
    unordered_map<char, int> mp;
    for (auto &&i : v)
    {
        mp[i]++;
    }
    int max1 = 0, max2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (mp[v[i]] > max1)
        {
            max2 = max1;
            max1 = mp[v[i]];
        }

        if (mp[v[i]] > max2 && mp[v[i]] != max1)
            max2 = mp[v[i]];
    }
    maxLength = max1 + max2;
    return maxLength;
}

// wrong probably
int findMaxFruits2(vector<char> &v)
{
    int maxLength = 0, currMax = 0;
    unordered_map<char, int> mp;
    for (auto &&i : v)
    {
        mp[i]++;
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] != v[i + 1])
        {
            currMax = mp[v[i]] + mp[v[i + 1]];
            maxLength = max(currMax, maxLength);
        }
    }

    return maxLength;
}

int findLength(const vector<char> &arr)
{
    int windowStart = 0, maxLength = 0;
    unordered_map<char, int> fruitFrequencyMap;
    // try to extend the range [windowStart, windowEnd]
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        fruitFrequencyMap[arr[windowEnd]]++;
        // shrink the sliding window, until we are left with '2' fruits in the frequency map
        while (fruitFrequencyMap.size() > 2)
            fruitFrequencyMap[arr[windowStart]]--;
        if (fruitFrequencyMap[arr[windowStart]] == 0)
        {
            fruitFrequencyMap.erase(arr[windowStart]);

            windowStart++; // shrink the window
        }
        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
}

int main()
{
    vector<char> arr = {'B', 'B', 'B', 'A', 'C', 'C'};
    // cout << findMaxFruits(arr);
    // cout<<findMaxFruits2(arr);
    cout<<findLength(vector<char>{'B', 'B', 'B', 'A', 'C', 'C'});

    return 0;
}