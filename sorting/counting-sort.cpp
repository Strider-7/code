#include <bits/stdc++.h>
using namespace std;

string countingSort(string str)
{

    int arr[26]{};
    for (int i = 0; i < str.length(); i++)
        arr[str[i] - 'a']++;
    int j = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            while (arr[i] != 0)
            {
                str[j++] = 97 + i;
                arr[i]--;
            }
        }
    }
    return str;
}

int main()
{

    string str = "encyclopedia";
    str = countingSort(str);
    cout << str;

    return 0;
}