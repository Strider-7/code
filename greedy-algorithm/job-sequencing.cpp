#include <bits/stdc++.h>

using namespace std;

bool myComp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int maxProfit(vector<pair<int, int>> &v)
{
    sort(v.begin(), v.end(), myComp);
    int n = v.size();
    int profit[n]{};
    bool slot[n]{};

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, v[i].first) - 1; j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                profit[j] = v[i].second;
                slot[j] = true;
                break;
            }
        }
    }

    return accumulate(profit, profit + n, 0);
}

int main()
{
    vector<pair<int, int>> v = {{2, 100}, {1, 50}, {2, 10}, {1, 20}, {3, 30}};
    vector<pair<int, int>> v2 = {{2, 50}, {2, 60}, {3, 20}, {3, 30}};

    cout << maxProfit(v) << endl;
    cout << maxProfit(v2) << endl;

    return 0;
}