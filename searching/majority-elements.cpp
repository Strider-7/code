#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> &nums)
{
    int count1 = 0, count2 = 0, a = 0, b = 1;

    for (auto n : nums)
    {
        if (a == n)
        {
            count1++;
        }
        else if (b == n)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            a = n;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            b = n;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (auto n : nums)
    {
        if (n == a)
            count1++;
        else if (n == b)
            count2++;
    }

    vector<int> res;
    if (count1 > nums.size() / 3)
        res.push_back(a);
    if (count2 > nums.size() / 3)
        res.push_back(b);
    return res;
}

int main()
{
    vector<int> v = {1, 1, 1, 3, 3, 2, 2, 2};
    v = majorityElement(v);
    for (auto &&i : v)
    {
        cout << i << endl;
    }

    return 0;
}