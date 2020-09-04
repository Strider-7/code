#include <bits/stdc++.h>

using namespace std;

int countWays(int n, int i = 0)
{
    if (i == n)
        return 1;
    if (i > n)
        return 0;
    return countWays(n, i + 1) + countWays(n, i + 2);
}
// fibonacci n+1

int main()
{
    cout << countWays(5);
    return 0;
}