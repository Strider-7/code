#include <bits/stdc++.h>

using namespace std;

bool myComp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int activitySelection(vector<pair<int, int>> v)
{
    sort(v.begin(), v.end());
    // for (auto &&i : v)
    //     cout << i.first << " " << i.second << endl;

    int n = v.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = 1;
        pair<int, int> prev = v[i];
        for (int j = i + 1; j < n; j++)
        {
            if (prev.second < v[j].first)
            {
                curr++;

                cout << prev.first << " " << prev.second << "----" << v[j].first << " " << v[j].second << endl;
                prev = v[j];
            }
        }
        res = max(res, curr);
    }
    return res;
}

int activitySelection2(vector<pair<int, int>> v)
{

    sort(v.begin(), v.end(), myComp);
    int res = 1;
    pair<int, int> last = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first >= last.second)
        {
            res++;
            last = v[i];
        }
    }   
    return res;
}

int main()
{
    vector<pair<int, int>> v = {{2, 3}, {4, 5}, {5, 8}, {6, 10}};
    cout << activitySelection2(v);

    return 0;
}