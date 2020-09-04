#include<bits/stdc++.h>
using namespace std;
#define N 105


 // } Driver Code Ends











/*  Function to rotate matrix by 90 degrees
*   n: input for matrix size
*   N: size defined globally
*/
void rotateby90(int n, int a[][N]){
    
      
    for(int i=0;i<n;i++)
     for(int j=0;j<N;j++)
      swap(a[i][j], a[j][i]);
      
    for(int i=0;i<n;i++)
    {
     int top=0, bottom=n-1;
     while(top<=bottom)
     {
         swap(a[top][i], a[bottom][i]);
         top++;
         bottom--;
     }
    }
    
}




// { Driver Code Starts.

int main()
{
	int t;
	cin>>t; //inputting testcases
	while(t--)
	{
		int n;
		cin>>n; //inputing n for square matrix
		int a[N][N],i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>a[i][j]; //Inputting the matrix
			}
		}
		
		rotateby90(n, a);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<a[i][j]<<" "; //printing the resultant matrix
			}
		}
		cout<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends