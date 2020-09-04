#include <bits/stdc++.h>
using namespace std;



vector<int> memo(1000, -1);

int fib(int n)
{
    if (memo[n] == -1)
    {
        int res;
        if (n == 0 || n == 1)
            res = n;
        else
            res = fib(n - 1) + fib(n - 2);
        memo[n] = res;
    }
    return memo[n];
}

long long int fib2(long long int n)
{
    if (n <= 1)
        return n;
    else
        return fib(n - 2) + fib(n - 1);
}

int main()
{
    cout << fib(500) << endl;
    cout << fib2(500);

    return 0;
}