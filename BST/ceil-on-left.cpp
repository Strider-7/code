#include <bits/stdc++.h>

using namespace std;

vector <int> ceilOnLeft(vector <int> v) {
    vector <int> res;
    set <int> s;
    for (auto &&i : v)
    {
        s.insert(i);
        auto itr=s.upper_bound(i);
        if (itr==s.end())
            res.push_back(-1);
        else
            res.push_back(*itr);

    }
    return res;
}

int main() {

    vector <int> v={ 2, 8, 30, 15, 25, 12 };
    v=ceilOnLeft(v);
    for (auto &&i : v)
        cout<<i<<" ";



    return 0;

}