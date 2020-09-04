#include <bits/stdc++.h>
using namespace std;

bool isValid(int num)
{
    if (num == 0)
        return false;
    unordered_set<int> s = {1, 2, 3};
    while (num)
    {
        int digit = num % 10;
        if (!s.count(digit))
            return false;
        num = num / 10;
    }
    return true;
}

int main()
{
    int arr[] = {0, 384, 946, 910, 210, 759, 222, 589, 423, 947, 507, 31, 414, 169, 901, 592};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (isValid(arr[i]))
        {
            cout << arr[i] << " ";
            flag = false;
        }
    }
    if (flag)
        cout << -1 << endl;
    else
        cout << endl;
    return 0;
}