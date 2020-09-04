#include <bits/stdc++.h>
using namespace std;

void frequency(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] == arr[i])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
            continue;
        int freq = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[i])
                freq++;
        }
        cout << arr[i] << " " << freq << endl;
    }
}

void frequency2(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]])
        {
            cout << arr[i] << " " << mp[arr[i]] << endl;
            mp.erase(arr[i]);
        }
    }
}

int main()
{
    int arr[] = {1, 1, 2, 1, 2, 1, 8, 8, 2, 2, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    frequency2(arr, n);

    return 0;
}