#include <iostream>
#include <algorithm>
using namespace std;

int maxProfit(int arr[], int start, int end)
{
    if (end <= start)
        return 0;
    int profit = 0;
    for (int i = start; i < end - 1; i++)
    {
        for (int j = i + 1; j < end; j++)
        {
            if (arr[j] > arr[i])
            {
                int currProfit = arr[j] - arr[i] + maxProfit(arr, start, i - 1) + maxProfit(arr, j + 1, end);
                profit = max(profit, currProfit);
            }
        }
    }
    return profit;
}

int maxProfit(int arr[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            profit += arr[i] - arr[i - 1];
    }
    return profit;
}

int main()
{
    int arr[6] = {7,1,5,3,6,4};
    cout << maxProfit(arr, 0, 5)<<endl;
    cout << maxProfit(arr, 5)<<endl;

    return 0;
}