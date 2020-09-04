#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>& grid, int x, int y, int &sum)
    {
        grid[x][y]=-1;
        if(x+1<m && grid[x+1][y]==1) dfs(grid,x+1,y,++sum);
        if(y+1<n && grid[x][y+1]==1) dfs(grid,x,y+1,++sum);
        if(x-1>=0 && grid[x-1][y]==1) dfs(grid,x-1,y,++sum);
        if(y-1>=0 && grid[x][y-1]==1) dfs(grid,x,y-1,++sum);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0)return 0;
        m=grid.size();n=grid[0].size();int i,j,ans=0,sum;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    sum=1;
                    dfs(grid,i,j,sum);
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};