#include <bits/stdc++.h>

using namespace std;
int minSubArray(vector<int> &v, int start, int end)
{
    int min = INT32_MAX;
    for (int i = start; i < end; i++)
    {
        if (v[i] < min)
            min = v[i];
    }
    return min;
}
vector<int> minSlidingWindow(vector<int> &nums, int k)
{
    int min = 0;
    vector<int> res;
    for (int i = 0; i <= nums.size() - k; i++)
    {
        min = minSubArray(nums, i, i + k);
        res.push_back(min);
    }
    return res;
}

vector<int> printMaxOfMin(vector<int> arr)
{
    int windowSize = 1;
    vector<int> res;
    for (int i = 1; i <= arr.size(); i++)
    {
        vector<int> v = minSlidingWindow(arr, i);
        int x = *max_element(v.begin(), v.end());
        res.push_back(x);
    }
    return res;
}

int main()
{
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};

    vector<int> v = printMaxOfMin(arr);

    for (auto &&i : v)
        cout << i << " ";
}