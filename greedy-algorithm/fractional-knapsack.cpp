#include <bits/stdc++.h>

using namespace std;

bool myComp(pair<int, int> a, pair<int, int> b)
{
    float x, y;
    x = a.second / (double)a.first;
    y = b.second / (double)b.first;
    return x > y;
}

int maxValue(vector<pair<int, int>> &v, int w)
{
    sort(v.begin(), v.end(), myComp);
    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cout << w << " " << res << endl;
        if (v[i].first <= w)
        {
            res += v[i].second;
            w -= v[i].first;
        }
        else
        {
            res += (v[i].second * w) / v[i].first;
            return res;
        }
        
    }

    return res;
}

int main()
{
    vector<pair<int, int>> v = {{50, 600}, {20, 500}, {30, 400}};
    cout << maxValue(v, 70);

    return 0;
}