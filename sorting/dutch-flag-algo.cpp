#include <iostream>
using namespace std;

// Partition routine using Dutch National Flag Algorithm
pair<int,int> Partition(int arr[], int start, int end)
{
	int mid = start;
	int pivot = arr[end];

	while (mid <= end)
	{
		if (arr[mid] < pivot)
		{
			swap(arr[start], arr[mid]);
			++start, ++mid;
		}
		else if (arr[mid] > pivot)
		{
			swap(arr[mid], arr[end]);
			--end;
		}
		else
		{
			++mid;
		}
	}

	// arr[start .. mid - 1] contains all occurrences of pivot
	return make_pair(start - 1, mid);
}

// Three-way Quicksort routine
void quicksort(int arr[], int start, int end)
{
	// base condition for 0 or 1 elements
	if (start >= end)
		return;

	// handle 2 elements separately as Dutch national flag
	// algorithm will work for 3 or more elements
	if (start - end == 1)
	{
		if (arr[start] < arr[end])
			swap(arr[start], arr[end]);
		return;
	}

	// rearrange the elements across pivot using Dutch
	// national flag problem algorithm
	pair<int,int> pivot = Partition(arr, start, end);

	// recur on sub-array containing elements that are less than pivot
	quicksort(arr, start, pivot.first);

	// recur on sub-array containing elements that are more than pivot
	quicksort(arr, pivot.second, end);
}

// Quicksort using Dutch National Flag Algorithm
int main()
{
	int arr[] = { 2, 6, 5, 2, 6, 8, 6, 1, 2, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	quicksort(arr, 0, n - 1);

	// print the sorted array
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}