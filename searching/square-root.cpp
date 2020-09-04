#include <bits/stdc++.h>
using namespace std;
int sqrt(int n)
{
    if (n == 0 || n == 1)
        return n;
    int low = 1, high = n, mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid * mid == n)
            return mid;
        if (mid * mid < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return mid * mid < n ? mid : mid - 1;
}

int main()
{
    cout << sqrt(10000);
    return 0;
}