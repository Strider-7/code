#include <bits/stdc++.h>
using namespace std;
float medianTwoSortedArr(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0, j = 0;
    float median = 0.0;
    vector<int> v;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            v.push_back(arr1[i]);
            i++;
        }
        else
        {
            v.push_back(arr2[j]);
            j++;
        }
    }
    for (; i < n1; i++)
        v.push_back(arr1[i]);
    for (; j < n2; j++)
        v.push_back(arr1[j]);
    int n = v.size();

    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << v[n / 2 - 1] << " " << v[n / 2] << endl;

    median = n % 2 == 1 ? v[n / 2] : (float)(v[n / 2 - 1] + v[n / 2]) / 2;

    return median;
}

int main()
{

    int arr1[] = {1, 2, 4, 5, 19};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {3, 6, 7, 8, 16};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << medianTwoSortedArr(arr1, n1, arr2, n2);

    return 0;
}