#include <bits/stdc++.h>
using namespace std;

int maxLength(int arr[], int n)
{
    int maxLen = 0, curr = 1;
    bool flag = arr[0] % 2;

    for (int i = 1; i < n; i++)
    {
        bool flag2 = arr[i] % 2;

        flag2 == flag ? curr = 1 : curr++;
        // cout << flag2 << " " << curr << endl;
        flag = flag2;
        maxLen = max(curr, maxLen);
    }
    return maxLen;
}

int main()
{
    int arr[6] = {10, 20, 30, 31, 25, 25};
    cout << maxLength(arr, 6);

    return 0;
}