#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &v, int start, int end)
{
    int max = INT32_MIN;
    for (int i = start; i < end; i++)
    {
        if (max < v[i])
            max = v[i];
    }
    return max;
}
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int max = 0;
    vector<int> res;
    for (int i = 0; i <= nums.size() - k; i++)
    {
        max = maxSubArray(nums, i, i + k);
        res.push_back(max);
    }
    return res;
}