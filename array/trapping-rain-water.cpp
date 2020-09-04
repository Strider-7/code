#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int trappingWater(int arr[], int low, int high)
{
    int res = 0;
    int h = arr[low];
    for (int i = low + 1; i < high; i++)
    {
        if (h - arr[i] >= 0)
            res += h - arr[i];
    }
    return res;
}
// O(n^2)
int totalWater(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int lMax = arr[i], rMax = arr[i];
        for (int j = 0; j < i; j++)
            lMax = max(lMax, arr[j]);
        for (int j = i + 1; j < n; j++)
            rMax = max(rMax, arr[j]);
        int h = min(lMax, rMax);

        res += h - arr[i];
    }
    return res;
}

// O(n)

int trappedWater(int arr[], int n)
{
    int lmax[n], rmax[n], res = 0;
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++)
        lmax[i] = max(arr[i], lmax[i - 1]);

    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rmax[i] = max(arr[i], rmax[i + 1]);

    for (int i = 0; i < n; i++)
        res += min(lmax[i], rmax[i]) - arr[i];

    return res;
}

int trap(const vector<int> &heights) /*O(N) time O(1) space*/
{

    int left = 0, right = heights.size() - 1, water = 0;

    int maxLeft = heights[left];
    int maxRight = heights[right];

    while (left < right)
    {
        if (heights[left] <= heights[right])
        {
            left++;
            maxLeft = max(maxLeft, heights[left]);
            water += (maxLeft - heights[left]);
        }
        else
        {
            right--;
            maxRight = max(maxRight, heights[right]);
            water += (maxRight - heights[right]);
        }
    }

    return water;
}

int main()
{
    int arr[5] = {3, 0, 1, 2, 5};
    cout << totalWater(arr, 5) << endl;
    cout << trappedWater(arr, 5) << endl;
    cout << trap(vector<int>{3, 0, 1, 2, 5}) << endl;

    return 0;
}
