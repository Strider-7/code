#include <bits/stdc++.h>
using namespace std;

int findSum(string str)
{
    string temp = "";

    int sum = 0;
    for (char ch : str)
    {
        if (isdigit(ch))
            temp += ch;

        else
        {
            sum += atoi(temp.c_str());
            temp = "";
        }
    }

    return sum + atoi(temp.c_str());
}

int main()
{
    string s1 = "a1b23cde100";
    cout << findSum(s1);

    return 0;
}