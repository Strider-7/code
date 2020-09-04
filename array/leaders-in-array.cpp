#include <bits/stdc++.h>
using namespace std;
void leaders(int arr[], int n)
{
    vector<int> res;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
            {
                // break;
                res.push_back(-1);
                break;
            }

            if (j == n - 1)
                res.push_back(arr[i]);
        }
    }
    res.push_back(arr[n - 1]);

    for (auto &&i : res)
    {
        if (i != -1)
            cout << i << " ";
    }
}

void leaderCheck(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            cout << arr[i] << " ";
    }
}

void leader(int arr[], int n)
{
    cout << arr[n - 1] << " ";
    int currLeader = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > currLeader)
        {
            currLeader = arr[i];
            cout << currLeader << " ";
        }
    }
}

int main()
{
    int arr[7] = {7, 10, 4, 10, 6, 5, 2};
    leaders(arr, 7);
    cout << endl;
    leaderCheck(arr, 7);
    cout << endl;
    leader(arr, 7);

    return 0;
}  