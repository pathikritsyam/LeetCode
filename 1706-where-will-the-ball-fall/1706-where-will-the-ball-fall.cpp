class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m,-1));
        for(int j=0;j<m;j++)dp[n][j]=j;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&j+1<m&&grid[i][j+1]==1)dp[i][j]=dp[i+1][j+1];
                if(grid[i][j]==-1&&j>0&&grid[i][j-1]==-1)dp[i][j]=dp[i+1][j-1];
            }
        }
        return dp[0];
    }
};