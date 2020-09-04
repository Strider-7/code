#include <bits/stdc++.h>
using namespace std;

bool isLucky(int n, int &counter)
{
    if (counter > n)
        return 1;
    if (n % counter == 0)
        return 0;

    n -= n / counter;
    counter++;
    return isLucky(n, counter);
   
}