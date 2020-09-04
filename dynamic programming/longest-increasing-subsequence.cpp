#include <bits/stdc++.h>

using namespace std;
// wrong approach
int longest(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = 1, prev = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > prev)
            {
                curr++;
                prev = arr[j];
            }
        }
        res = max(res, curr);
    }

    return res;
}

// O(n^2)
int LIS(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], 1 + lis[j]);
    }

    return *max_element(lis, lis + n);
}

// using binary search O(NlogN)
int lengthOfLIS(const vector<int> &nums)
{
    vector<int> subseq;
    for (auto n : nums)
    {
        auto it = lower_bound(begin(subseq), end(subseq), n);
        if (it == end(subseq))
            subseq.push_back(n);
        else
            *it = n;
    }

    return subseq.size();
}

int main()
{
    int arr[] = {4, 10, 6, 5, 8, 11, 2, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << longest(arr, n);
    cout << LIS(arr, n);

    return 0;
}