#include <bits/stdc++.h>

using namespace std;

int maxCount(int arr[], int n)
{

    int mCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            int j = i + 1;
            int count = 1;
            while (arr[j] == 1)
            {
                count++;
                j++;
            }
            mCount = max(mCount, count);
        }
    }
    return mCount;
}

int countOfOne(int arr[], int n)
{
    int curr = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            curr = 0;

        else
        {
            curr++;
            res = max(curr, res);
        }
    }
    return res;
}

int main()
{
    int arr[10] = {0, 1, 1, 1, 0, 1, 1, 1, 0, 0};
    cout << maxCount(arr, 10) << endl;
    cout << countOfOne(arr, 10) << endl;

    return 0;
}