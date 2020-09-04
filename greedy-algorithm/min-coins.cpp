#include <bits/stdc++.h>

using namespace std;

int minCoins(vector<int> v, int sum)
{
    sort(v.begin(), v.end(), greater<int>());
    int res = 0;
    for (auto &&i : v)
    {
        if (i <= sum)
        {
            int c = sum / i;
            res += c;
            sum -= c * i;
        }

        if (!sum)
            break;
    }
    return res;
}

int main()
{
    vector<int> v = {5, 10, 1, 2};
    cout << minCoins(v, 58);

    return 0;
}