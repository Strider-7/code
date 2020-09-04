#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

int lexicographicRank(string s)
{
    int n = s.length(), res = 1;
    int mul = factorial(n);
    int count[26]{};
    for (int i = 0; i < n; i++)
        count[s[i] - 'a']++;

    for (int i = 1; i < 26; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < n - 1; i++)
    {
        mul = mul / (n - i);
        res = res + count[s[i] - 'a' - 1] * mul;
        for (int j = s[i] - 'a'; j < 26; j++)
            count[j]--;
    }

    return res;
}

void permute(string a, int l, int r, vector<string> &res)
{

    if (l == r)
    {
        res.push_back(a);
        return;
    }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l + 1, r, res);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}

int main()
{
    string s1 = "sil", s2 = "koaugzqr";

    vector<string> v;
    permute(s2, 0, s2.length() - 1, v);
    sort(v.begin(), v.end());
    // for (auto &&i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == s2)
        {
            cout << i + 1 << endl;
            break;
        }
    }

    // cout << lexicographicRank(s2);

    return 0;
}