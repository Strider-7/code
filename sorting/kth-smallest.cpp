#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Function to find the K'th smallest element in the
// array using max-heap
int findKthSmallest(vector<int> const &v, int k)
{
    // create a max-heap using std::priority_queue and
    // insert first k elements of the array into the heap
    priority_queue<int, vector<int>> pq(v.begin(), v.begin() + k);

    // do for remaining array elements
    for (int i = k; i < v.size(); i++)
    {
        // if current element is less than the root of the heap
        if (v[i] < pq.top())
        {
            // replace root with the current element
            pq.pop();
            pq.push(v[i]);
        }
    }

    // return the root of max-heap
    return pq.top();
}

int lomuto(int arr[], int l, int h)
{
    int pivot = arr[h], i = l - 1;

    for (int j = l; j <= h - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);

    return i + 1;
}

int kthSmallest(int arr[], int n, int k)
{

    int l = 0, r = n - 1;
    while (l <= r)
    {
        int p = lomuto(arr, l, r);
        if (p == k - 1)
            return p;
        else if (p > k - 1)
            r = p - 1;
        else
            l = p + 1;
    }
    return -1; 
}

// Find K'th smallest element in an array
int main()
{
    vector<int> vec = {7, 4, 6, 3, 9, 1};
    const size_t k = 3;

    cout << "K'th smallest element in the array is " << findKthSmallest(vec, k);

    nth_element(vec.begin(), vec.begin() + k, vec.end());

    cout << endl
         << vec[k - 1];

    return 0;
}