// Given an array arr[] of N elements. 
// The task is to count maximum number of distinct smaller elements on right side of any array element. 
// For example, in {10, 6, 9, 7, 20, 19, 21, 18, 17, 16}, the result is 4. 
//  Note that 20 has maximum 4 smaller elements on right side. 


#include<bits/stdc++.h>
using namespace std;

int arr[1000000];

set<int> s;

int countSmallerRight(int n) {

    int countSmaller = 0;

    // iterating over elements
    for (int i = n-1; i >= 0; i--) {
        s.insert(arr[i]);

        // find the first element that is lower than arr[i]
        auto it = s.lower_bound(arr[i]);

        // Find the distance between above found element 
        // and the beginning of the set using distance function
        if (distance(s.begin(), it) > countSmaller)
            countSmaller = distance(s.begin(), it);
    }

    return countSmaller;

}


int main() {

    int t;
    cin >> t;

    while (t--) {
        s.clear();

        int n;
        cin >> n;

        for (int i = 0;i<n;i++) {
            cin >> arr[i];
        }

        cout << countSmallerRight(n) << endl;

    }

    return 0;
}