#include <bits/stdc++.h>
using namespace std;

int findLengthOfLCIS(const vector<int> &nums)
{
    int curr = 1, maxLen = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            curr++;
            maxLen = max(curr, maxLen);
        }
        else
        {
            curr = 1;
        }
    }
    return maxLen;
}

int main()
{
    int arr[6] = {10, 20, 30, 31, 25, 25};
    cout << findLengthOfLCIS(vector<int>{10, 2, 30, 31, 25, 25});

    return 0;
}