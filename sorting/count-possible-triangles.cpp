
// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

void CountTriangles(vector<int> A)
{

    int n = A.size();

    sort(A.begin(), A.end());

    int count = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        int l = 0, r = i - 1;
        while (l < r)
        {
            if (A[l] + A[r] > A[i])
            {

                // If it is possible with a[l], a[r]
                // and a[i] then it is also possible
                // with a[l+1]..a[r-1], a[r] and a[i]
                count += r - l;

                // checking for more possible solutions
                r--;
            }
            else

                // if not possible check for
                // higher values of arr[l]
                l++;
        }
    }
    cout << "No of possible solutions: " << count;
}
int main()
{

    vector<int> A = {26, 9, 27, 22, 16, 27};

    CountTriangles(A);
}

// #include <bits/stdc++.h>
// using namespace std;

// long long arr[10000000]{26, 9, 27, 22, 16, 27};

// long long findNumberOfTriangles(long long n)
// {
//     long long res = 0;

//     sort(arr, arr + n);
//     int a, b, c;

//     for (int i = 0; i < n - 2; i++)
//     {
//         a = arr[i];

//         for (int low = i + 1; low < n - 1; low++)
//         {

//             int high = n - 1;
//             int last = INT32_MIN;
//             // unordered_set<int> s(arr + low + 1, arr + n);
//             while (high > low)
//             {
//                 if (arr[high] != last)
//                 {
//                     last = arr[high];
//                     res++;
//                 }
//                 high--;
//             }
//         }
//     }
//     return res;
// }

// int main()
// {
//     // int arr[] = {26, 9, 27, 22, 16, 27};
//     cout << findNumberOfTriangles(6);

//     return 0;
// }
