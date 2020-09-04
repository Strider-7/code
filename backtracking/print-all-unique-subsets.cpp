#include <bits/stdc++.h>
using namespace std;

// void subsets(vector<int> &v, vector<vector<int>> &res, vector<int> curr, int i = 0)
// {
//     if (i >= v.size())
//     {
//         res.push_back(curr);
//         return;
//     }
//     curr.push_back(v[i]);
//     subsets(v, res, curr, i + 1);
//     curr.pop_back();
//     subsets(v, res, curr, i + 1);
// }

// vector<vector<int>> AllSubsets(vector<int> v, int n)
// {
//     vector<vector<int>> res;
//     vector<int> curr;
//     subsets(v, res, curr);
//     return res;
// }

void fun(vector<int> A, int index, vector<int> current, vector<vector<int>> &result){
    if(index>=A.size()){
        result.push_back(current);
        return;
    }
    int curIndex=index+1;
    while(curIndex<A.size() && A[curIndex]==A[index]){
        curIndex++;
    }
    int count=curIndex - index;
    for(int i=0;i<=count;i++){
        for(int j=0;j<i;j++){
            current.push_back(A[index]);
        }
        fun(A, curIndex, current, result);
        for(int j=0;j<i;j++){
            current.pop_back();
        }
    }
}

vector<vector<int> > AllSubsets(vector<int> v, int n)
{
    vector<vector<int>> res;
    vector <int> curr;
    int i=0;
    sort(v.begin(),v.end());
    fun(v,i,curr,res);
    return res;
}

int main()
{
    vector<int> v = {1, 2, 2};
    vector<vector<int>> x;
    x = AllSubsets(v, 3);
    sort(x.begin(),x.end());
    for (auto &&i : x)
    {
        for (auto &&j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}