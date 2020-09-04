#include <bits/stdc++.h>
using namespace std;

// recursive
int catalan(int n)
{
    if (n == 0)
        return 1;

    int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);
    return res;
}

// dp
int catalan2(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];
    }
    return dp[n];
}

// combinatorics
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int res = n;
    while (n > 1)
    {
        n--;
        res *= n;
    }
    return res;
}

unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// A Binomial coefficient based function to find nth catalan
// number in O(n) time
unsigned long int catalan3(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2 * n, n);

    // return 2nCn/(n+1)
    return c / (n + 1);
}

int main()
{
    cout << catalan(5) << endl;
    cout << catalan2(5) << endl;
    cout << catalan3(5) << endl;
    return 0;
}