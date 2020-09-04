#include <bits/stdc++.h>

using namespace std;

struct Triplet
{
    int val, arrayPos, valPos;
    Triplet(int x, int y, int z) {
        val=x, arrayPos=y, valPos=z;

    }
};

struct myComp
{
    bool operator()(Triplet &t1, Triplet &t2) {
        return t1.val>t2.val;
    }
};

vector <int> mergeKSortedArrays(vector <vector<int>> &arr) {
    vector <int> res;
    priority_queue <Triplet, vector<Triplet>, myComp> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        Triplet t(arr[i][0], i, 0);
        pq.push(t);
    }
    while (!pq.empty())
    {
        Triplet curr=pq.top();
        pq.pop();
        res.push_back(curr.val);
        int arrPos=curr.arrayPos, valPos=curr.valPos;
        if (valPos+1<arr[arrPos].size())
            pq.push(Triplet(arr[arrPos][valPos+1], arrPos, valPos+1));
    }
    return res;


}



int main()
{

    vector <vector<int>> v={ { 1, 5, 8, 15, 19 }, { 2, 14, 18, 24 }, { 1, 2, 4, 6, 8, 10 } };

    vector <int> res=mergeKSortedArrays(v);
    for (auto &&i : res)
        cout<<i<<" ";





    return 0;
}