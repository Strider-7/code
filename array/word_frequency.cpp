#include <bits/stdc++.h>
using namespace std;

void wordFrequency(string str){
    unordered_map <string,int> U;
    stringstream ss(str); 
    string word="";
    while (ss>>word)
      U[word]++;
    for (auto &&i : U)
    {
        cout<<i.first<<"="<<i.second<<endl;
    }
    
    

}

int main(){
    string str="geeks for geeks geeks quiz practice qa for";
    wordFrequency(str);
    return 0;
}