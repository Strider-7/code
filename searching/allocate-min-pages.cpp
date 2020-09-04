#include <bits/stdc++.h>
using namespace std;

bool isValidConfig(int arr[], int n, int m, int ans)
{
    int student_count = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (pages + arr[i] > ans)
        {
            student_count++;
            pages = arr[i];
            if (student_count > m)
                return false;
        }
        else
            pages += arr[i];
    }
    return true;
}

int allocation(int arr[], int n, int m)
{
    if (m > n)
        return -1;
    int res = arr[n - 1];
    int low = arr[n - 1], high = accumulate(arr, arr + n, 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValidConfig(arr, n, m, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

// int allocation(int arr[], int n, int m)
// {
//     int student_count = 1;
//     int low = 0, high = accumulate(arr, arr + n, 0);
//     while (low < high)
//     {
//         int mid = low + (high - low) / 2, currSum = 0, currMax = INT32_MIN;
//         for (int i = 0; i < n; i++)
//         {
//             currSum += arr[i];

//             if (currSum > mid)
//             {
//                 student_count++;
//                 currSum = arr[i];
//             }

//             currMax = max(currMax, currSum);
//         }

//         if (student_count > m)
//             low = mid;

//         else
//             high = mid;

//         if (low == high)
//             return currMax;
//     }
//     return -1;
// }

// int allocation(int arr[],int n){
// int sum = 0, currSum = arr[0], currMax = INT32_MIN, res = 0;
// sum = accumulate(arr, arr + n, 0);
// currSum = arr[0];
// currMax = max(currSum, sum - currSum);
// res = currMax;
// for (int i = 1; i < n; i++)
// {
//     currSum += arr[i];
//     currMax = max(currSum, sum - currSum);
//     res = min(res, currMax);
// }
// return res;
// }

int main()
{
    int arr[] = {51, 151, 227, 163, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    cout << allocation(arr, n, 3);
    return 0;
}