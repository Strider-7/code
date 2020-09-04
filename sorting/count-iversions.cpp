// C++ program to Count 
// Inversions in an array 
// using Merge Sort 
#include <bits/stdc++.h> 
using namespace std; 

int _mergeSort(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right); 

/* This function sorts the input array and returns the 
number of inversions in the array */
int mergeSort(int arr[], int array_size) 
{ 
	int temp[array_size]; 
	return _mergeSort(arr, temp, 0, array_size - 1); 
} 

/* An auxiliary recursive function that sorts the input array and 
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
	int mid, inv_count = 0; 
	if (right > left) { 
		/* Divide the array into two parts and 
		call _mergeSortAndCountInv() 
		for each of the parts */
		mid = (right + left) / 2; 

		/* Inversion count will be sum of 
		inversions in left-part, right-part 
		and number of inversions in merging */
		inv_count += _mergeSort(arr, temp, left, mid); 
		inv_count += _mergeSort(arr, temp, mid + 1, right); 

		/*Merge the two parts*/
		inv_count += merge(arr, temp, left, mid + 1, right); 
	} 
	return inv_count; 
} 

/* This funt merges two sorted arrays 
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left, 
		int mid, int right) 
{ 
	int i, j, k; 
	int inv_count = 0; 

	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) { 
		if (arr[i] <= arr[j]) { 
			temp[k++] = arr[i++]; 
		} 
		else { 
			temp[k++] = arr[j++]; 

			/* this is tricky -- see above 
			explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i); 
		} 
	} 

	/* Copy the remaining elements of left subarray 
(if there are any) to temp*/
	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 

	/* Copy the remaining elements of right subarray 
(if there are any) to temp*/
	while (j <= right) 
		temp[k++] = arr[j++]; 

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 

	return inv_count; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 20, 6, 4, 5 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int ans = mergeSort(arr, n); 
	cout << " Number of inversions are " << ans; 
	return 0; 
} 

// This is code is contributed by rathbhupendra 


// #include <bits/stdc++.h>
// using namespace std;

// int countMerge(int arr[], int low, int mid, int high)
// {
//     int n1 = mid - low + 1, n2 = high - mid, count = 0;
//     int left[n1], right[n2];
//     int i = 0, j = 0, k = low;
//     while (i < n1 && j < n2)
//     {
//         if (left[i] <= right[j])
//         {
//             arr[k++] = left[i++];
//         }
//         else
//         {
//             arr[k++] = right[j++];
//             count = count + (n1 - i);
//             // cout << count << endl;
//         }
//     }
//     while (i < n1)
//         arr[k++] = left[i++];
//     while (j < n2)
//         arr[k++] = left[j++];

//     return count;
// }

// int countInv(int a[], int l, int h)
// {
//     int res = 0;
//     if (l < h)
//     {
//         int mid = (l + h) / 2;
//         res += countInv(a, l, mid);
//         res += countInv(a, mid + 1, h);
//         res += countMerge(a, l, mid + 1, h);
//     }
//     return res;
// }

int countInversion(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                res++;
        }
    }
    return res;
}

// int main()
// {
//     int arr[] = {51, 151, 227, 163, 55};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << countInv(arr, 0, n);

//     return 0;
// }