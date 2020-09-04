#include <bits/stdc++.h>

using namespace std;

struct val
{
    int first;
    int second;
};

bool myComp(val p1, val p2)
{
    return p1.first < p2.first;
}

int maxChainLen(struct val arr[], int n)
{
    sort(arr, arr + n, myComp);
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[j].second < arr[i].first)
                lis[i] = max(lis[i], 1 + lis[j]);
    }

    return *max_element(lis, lis + n);
}