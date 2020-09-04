#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str,int start,int end){
    if(start >=end) return true;
    if(str[start]!=str[end])
        return false;
    return isPalindrome(str,start+1,end-1);
}

int main(){
    string str="kayak";
    cout<<isPalindrome(str,0,str.length()-1);
    return 0;
}