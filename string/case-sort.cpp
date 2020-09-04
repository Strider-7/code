#include <bits/stdc++.h>
using namespace std;

bool mycomp(char &a, char &b)
{
    return tolower(a) < tolower(b);
}

string caseSort(string str)
{

    sort(str.begin(), str.end(), mycomp);
    return str;
}

int main()
{
    string s1 = "defRTSersUXI";
    cout << caseSort(s1);

    return 0;
}