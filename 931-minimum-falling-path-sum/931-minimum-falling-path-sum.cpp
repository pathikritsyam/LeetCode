class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int res=1e9;
        for(int j=0;j<n;j++){
            res=min(res,dfs(n-1,j,matrix,dp));
        }
        return res;
    }
    int dfs(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        int m=matrix.size(),n=matrix[0].size();//row and column sizes
        if(j<0||j>n-1)return 1e9;//exclude path outside grid
        if(i==0)return matrix[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int up=matrix[i][j]+dfs(i-1,j,matrix,dp);
        int left_diagonal=matrix[i][j]+dfs(i-1,j-1,matrix,dp);
        int right_diagonal=matrix[i][j]+dfs(i-1,j+1,matrix,dp);
        return dp[i][j]=min(up,min(left_diagonal,right_diagonal));
    }
};