#include <bits/stdc++.h>

using namespace std;

int maxValue(int weight[], int value[], int n, int maxWeight)
{
    if (n == 0 || maxWeight == 0)
        return 0;

    if (weight[n - 1] > maxWeight)
        return maxValue(weight, value, n - 1, maxWeight);
    else
        return max(value[n - 1] + maxValue(weight, value, n - 1, maxWeight - weight[n - 1]),
                   maxValue(weight, value, n - 1, maxWeight));
}

// Memorization
int dp[100][100];

int knapSack(int weight[], int value[], int n, int maxWeight)
{
    if (dp[n][maxWeight] != -1)
        return dp[n][maxWeight];
    else
    {
        if (n == 0 || maxWeight == 0)
            dp[n][maxWeight] = 0;

        if (weight[n - 1] > maxWeight)
            dp[n][maxWeight] = maxValue(weight, value, n - 1, maxWeight);
        else
            dp[n][maxWeight] = max(value[n - 1] + maxValue(weight, value, n - 1, maxWeight - weight[n - 1]),
                                   maxValue(weight, value, n - 1, maxWeight));

        return dp[n][maxWeight];
    }
}
// DP
int knapsack(int weight[], int value[], int n, int maxWeight)
{
    int dp[n + 1][maxWeight + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weight[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
        }
    }
    return dp[n][maxWeight];
}

int main()
{
    int weight[] = {5, 4, 6, 3};
    int value[] = {10, 40, 30, 50};
    int n = sizeof(weight) / sizeof(weight[0]);

    cout << maxValue(weight, value, n, 10) << endl;
    cout << knapsack(weight, value, n, 10) << endl;
    memset(dp, -1, sizeof(dp));
    cout<<knapSack(weight,value,n,10);

    return 0;
}