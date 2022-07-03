class Solution {
public:
    int solve(vector<vector<int>> &grid,vector<vector<int>> &dp,int r,int c)
    {
      int n=grid.size(),m=grid[0].size();
      if(dp[r][c]!=-1)
        return dp[r][c];
      int dx[]={-1,0,0,1},dy[]={0,1,-1,0};
      int ans=1;
      for(int i=0;i<4;i++)
      {
        int x=r+dx[i],y=c+dy[i];
        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]>grid[r][c])
          ans=(ans+solve(grid,dp,x,y))%1000000007;
      }
      return dp[r][c]=ans;
    }
    int countPaths(vector<vector<int>>& grid) {
      int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if(dp[i][j]==-1)
            solve(grid,dp,i,j);
          ans=(ans+dp[i][j])%1000000007;
        }
      }
      return ans;
    }
};
