#include <bits/stdc++.h>
using namespace std;

int minFlips(int arr[], int n)
{
    int count0 = 0, count1 = 0,flips=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==0)
        {
            count1++;
        }
        
    }
    
}

int main()
{
    int arr[] = {1, 1, 0, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    return 0;
}