// Given N students sitting in a circle You have to distribute M candies to these students also ,
//  ith student takes i candies. if ith student didn't get required candies then he will not take it.
//   you have to distribute the candies starting from 1st student
// and moving along the circle of students till you cannot distribute to a student.
//  you need to output the left out candies.

#include <bits/stdc++.h>
using namespace std;

int leftCandies(int kids, int candies)
{
    int sum = kids * (kids + 1) / 2;
    candies = candies % sum;
    for (int i = 1; i < kids; i = (i + 1) % kids)
    {
        int temp = i;
        if (i == 0)
        {
            temp = kids;
        }
        if ((candies < temp) || (candies == 0))
            return candies;
        candies -= i;
    }
    return 0;
}

int main()
{
    cout << leftCandies(6, 100);
    return 0;
}