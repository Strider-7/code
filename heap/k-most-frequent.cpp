#include <bits/stdc++.h>

using namespace std;

struct compare { 
    bool operator()(pair<int, int> p1, pair<int, int> p2) 
    { 
        if (p1.second == p2.second) 
            return p1.first < p2.first; 
        return p1.second < p2.second; 
    } 
};
int kMostFrequent(int arr[], int n, int k) 
{ 
	unordered_map<int, int> um; 
    for (int i = 0; i < n; i++) 
        um[arr[i]]++; 
  
    vector<pair<int, int> > freq_arr(um.begin(), um.end()); 
  
    priority_queue<pair<int, int>,vector<pair<int, int>>,compare> pq(um.begin(), um.end()); 
    
    int res=0;
    for (int i = 1; i <= k; i++) { 
        res+=pq.top().second;
        pq.pop(); 
    } 
	
	return res;
} 

int main()
{
    int arr[] ={ 3, 1, 5, 5, 5, 5, 7, 8 };

    int n = sizeof(arr) / sizeof(arr[0]);


    cout<<kMostFrequent(arr, n, 2);


    return 0;
}