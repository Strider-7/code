#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, curr = 1;
        while (dep[j] >= arr[i] && j >= 0)
        {
            curr++;
            j--;
        }
        res = max(curr, res);
    }
    return res;
}

int minPlatform2(int arr[], int dep[], int n)
{
    int res = 0,curr=0;
    multimap<int, char> mp;
    for (int i = 0; i < n; i++)
    {
        mp.insert({arr[i], 'a'});
        mp.insert({dep[i], 'd'});
    }

    for (auto itr =mp.begin();itr!=mp.end();itr++)
    {
        if(itr->second=='a')
            curr++;
        else
            curr--;
        res=max(res,curr);
    }
    

    for (auto &&i : mp)
    {
        cout << i.first << " " << i.second << endl;
    }

    return res;
}

int minPlatform(int arrival[], int departure[], int n) 
{ 
  
    // as time range from 0 to 2359 in 24 hour clock, 
    // we declare an array for values from 0 to 2360 
    int platform[2361] = {}; 
    int requiredPlatform = 1; 
    for (int i = 0; i < n; i++) { 
  
        // increment the platforms for arrival 
        ++platform[arrival[i]];  
  
         // once train departs we decrease the platform count 
        --platform[departure[i] + 1]; 
    } 
  
    // We are running loop till 2361 because maximum time value 
    // in a day can be 23:60 
    for (int i = 1; i < 2361; i++) { 
  
        // taking cumulative sum of platform give us required 
        // number of platform fro every minute 
        platform[i] = platform[i] + platform[i - 1];  
        requiredPlatform = max(requiredPlatform, platform[i]); 
    } 
    return requiredPlatform; 
} 

int main()
{

    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << findPlatform(arr, dep, n);
    cout << minPlatform(arr, dep, n);
    return 0;
}