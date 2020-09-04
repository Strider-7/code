#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
            return false;
    }
    return true;
}
// wrong
string longest(string str, string curr = "", int i = 0)
{
    if (str.length() == i)
    {
        if (isPalindrome(curr))
            return curr;
        else
            return "";
    }
    string x = longest(str, curr + str[i], i + 1);
    string y = longest(str, curr, i + 1);

    return x.length() > y.length() ? x : y;
}

string expand(string str, int low, int high)
{
    int len = str.length();

    // run till str[low.high] is a palindrome
    while (low >= 0 && high < len && (str[low] == str[high]))
        low--, high++; // expand in both directions

    // return palindromic substring
    return str.substr(low + 1, high - low - 1);
}

// Function to find Longest Palindromic Substring in O(n^2) time
// and O(1) space
string LongestPalindromicSubstring(string str, int len)
{
    // max_str stores the maximum length palindromic substring
    // found so far

    string max_str = "", curr_str;

    // max_length stores the length of maximum length palindromic
    // substring found so far

    int max_length = 0, curr_length;

    // consider every character of given string as mid points and expand
    // in its both directions to find maximum length palindrome

    for (int i = 0; i < len; i++)
    {
        // find a longest odd length palindrome with str[i] as mid point

        curr_str = expand(str, i, i);
        curr_length = curr_str.length();

        // update maximum length palindromic substring if odd length
        // palindrome has greater length

        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }

        // find a longest even length palindrome with str[i] and str[i+1]
        // as mid points. Note that an even length palindrome has two
        // mid points

        curr_str = expand(str, i, i + 1);
        curr_length = curr_str.length();

        // update maximum length palindromic substring if even length
        // palindrome has greater length

        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }
    }

    return max_str;
}

// dp soln
int longestPalSubstr(string str)
{
    // get length of input string
    int n = str.size();

    // table[i][j] will be false if substring
    // str[i..j] is not palindrome.
    // Else table[i][j] will be true
    bool table[n][n];

    memset(table, 0, sizeof(table));

    // All substrings of length 1
    // are palindromes
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2.
    // k is length of substring
    for (int k = 3; k <= n; ++k)
    {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i + 1][j - 1] && str[i] == str[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    cout << "Longest palindrome substring is: ";

    cout << str.substr(start, maxLength);
    return maxLength;
}
// best
string longestPalindrome(string s)
{
    if (s.size() < 2)
        return s;
    int max_len = 0;
    int start_idx = 0;
    int i = 0;
    while (i < s.size())
    {
        int r_ptr = i;
        int l_ptr = i;
        //find the middle of a palindrome
        while (r_ptr < s.size() - 1 && s[r_ptr] == s[r_ptr + 1])
            r_ptr++;
        i = r_ptr + 1;
        //expand from the middle out
        while (r_ptr < s.size() - 1 && l_ptr > 0 && s[r_ptr + 1] == s[l_ptr - 1])
        {
            r_ptr++;
            l_ptr--;
        }
        int new_len = r_ptr - l_ptr + 1;
        if (new_len > max_len)
        {
            start_idx = l_ptr;
            max_len = new_len;
        }
    }
    return s.substr(start_idx, max_len);
}

int main()
{

    // cout << longest("abcbabd");
    longestPalSubstr("abcbabd");
    return 0;
}
