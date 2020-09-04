#include <bits/stdc++.h>
using namespace std;

void allSubStrings(string str, string curr = " ", int index = 0)
{
    if (index == str.length())
    {
        cout << curr << " ";
        return;
    }
    allSubStrings(str,curr,index+1);
    allSubStrings(str,curr+str[index],index+1);
}

int main()
{
    allSubStrings("abd");
    string s="ahsjvds";

    return 0;
}