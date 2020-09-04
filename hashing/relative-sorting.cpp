#include <bits/stdc++.h>
using namespace std;



void relativeSorting(int arr1[], int arr2[], int n1, int n2)
{
    unordered_map<int, int> mp1;

    for (int i = 0; i < n1; i++)
        mp1[arr1[i]]++;

    int j = 0;
    for (int i = 0; i < n2; i++)
    {
        auto itr = mp1.find(arr2[i]);
        if (itr != mp1.end())
        {
            int c = itr->second;
            while (c)
            {
                arr1[j++] = itr->first;
                c--;
            }
            mp1.erase(itr);
        }
    }

    int last = j;
    for (auto &&i : mp1)
    {
        int c = i.second;
        while (c)
        {
            arr1[j++] = i.first;
            c--;
        }
    }
    sort(arr1 + last, arr1 + n1);
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 1, 8, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    relativeSorting(arr1, arr2, n1, n2);

    return 0;
}