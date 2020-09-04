#include <bits/stdc++.h>
using namespace std;
bool checkRotatedAndSorted(int arr[], int n){
    
   int min=INT32_MAX,max=min=INT32_MAX,indexOfMin=0,indexOfMax=0;
   for(int i=0;i<n;i++){
       if(arr[i]<min){
           min=arr[i];
           indexOfMin=i;
       }
       if(arr[i]>max){
           max=arr[i];
           indexOfMax=i;
       }
            
   }
//   if(abs(indexOfMax-indexOfMin)!=1)
//     return false;
   bool flag=indexOfMin>indexOfMax?true:false;
   if(flag){
       for(int i=indexOfMin;i!=indexOfMax;i++)
       {
           if(arr[(i+1)%n]<arr[i]){
               return false;
           }
       }
       
   }
   else{
       
       for(int i=indexOfMin;i!=indexOfMax;i++)
       {
           if(arr[(i+1)%n]>arr[i]){
               return false;
           }
       }
       
   
   }
   return true;
    
    
}

int main()
{
    int arr[] = {3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<checkRotatedAndSorted(arr,n)<<endl;
    return 0;
}