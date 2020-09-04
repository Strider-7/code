// find if an array can be partitioned in equal sum sub arrays . we can move one element to the other partition

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, S = 0, leftsum = 0;
    cout << "enter size of array" << endl;
    cin >> n;
    vector<int> v(n, 0);
    cout << "enter values of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        S += v[i];
    }
    if (S & 1)
    {
        cout << " no solution " << endl;
        return 0;
    }
    // leftsum=S/2;
    unordered_map<int, int> first, second;
    first[v[0]]++;

    for (int i = 1; i < n; i++)
    {
        second[v[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        leftsum += v[i];
        if (leftsum == S / 2)
        {
            cout << "yes  " << endl;
        }
        else if (leftsum < S / 2)
        {
            if (second[S / 2 - leftsum])
            {
                cout << "yes  " << endl;
            }
        }
        else
        {
            if (second[leftsum - S / 2])
            {
                cout << "yes  " << endl;
            }
        }
        first[v[i] + 1]++;
        second[v[i] + 1]--;
    }

    return 0;
}
