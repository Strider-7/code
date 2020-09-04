#include <bits/stdc++.h>
using namespace std;

bool isRotated(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    int n = str1.length();
    string temp = str1.substr(0, 2) + str2.substr(0, n - 2);
    cout << temp << endl;
    if (temp == str1)
        return true;
    temp = str1.substr(0, n - 2) + str2.substr(0, 2);
    cout << temp << endl;
    if (temp == str1)
        return true;
    return false;
}

int main()
{
    string s1 = "amazon", s2 = "onamaz";

    cout << isRotated(s1, s2);

    return 0;
}