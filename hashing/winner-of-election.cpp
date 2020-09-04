// Given an array of names (consisting of lowercase characters) of candidates in an election.
//  A candidate name in array represents a vote casted to the candidate.
//  Print the name of candidate that received Max votes.
// If there is tie, print lexicographically smaller name.

#include <bits/stdc++.h>
using namespace std;

pair<string, int> winner(string arr[], int n)
{
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    string winner = "";
    int maxVotes = INT32_MIN;
    for (auto &&i : mp)
    {
        if (i.second == maxVotes)
            winner = winner < i.first ? winner : i.first;
        if (i.second > maxVotes)
        {
            maxVotes = i.second;
            winner = i.first;
        }
    }
    return make_pair(winner, maxVotes);
}

int main()
{

    string arr[] = {"john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<string, int> p = winner(arr, n);
    cout << p.first << " " << p.second;

    return 0;
}