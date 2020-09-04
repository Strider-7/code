#include <bits/stdc++.h>
using namespace std;

int unionUnsortedArr(int arr1[], int arr2[], int n1, int n2)
{
    unordered_set<int> s;
    for (int i = 0; i < n1; i++)
        s.insert(arr1[i]);
    for (int i = 0; i < n2; i++)
        s.insert(arr2[i]);
    return s.size();
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int N,M;
	    cin>>N>>M;
	    int arr1[N],arr2[M];
	    for (int i = 0; i < N; i++)
	        cin>>arr1[i];
	    for (int i = 0; i < M; i++)
	        cin>>arr2[i];  
	
	    cout<<unionUnsortedArr(arr1,arr2,N,M)<<endl;
	}
	return 0;
}