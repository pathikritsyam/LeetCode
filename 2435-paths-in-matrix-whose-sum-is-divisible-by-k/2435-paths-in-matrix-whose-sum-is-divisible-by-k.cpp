class Solution {
public:
    const int MOD=1e9+7;
    int f(vector<vector<int>>&G,int i,int j,int sum,int k,vector<vector<vector<int>>>&dp){
        if(i==0||j==0)return 0;
        if(i==1&&j==1){
            if((sum+G[0][0])%k==0)return 1;
            return 0;
        }
        if(dp[i][j][sum]!=-1)return dp[i][j][sum];
        return dp[i][j][sum]=(f(G,i-1,j,(sum+G[i-1][j-1])%k,k,dp)+f(G,i,j-1,(sum+G[i-1][j-1])%k,k,dp))%MOD;
    }
    int numberOfPaths(vector<vector<int>>& G, int k) {
        int n=G.size(),m=G[0].size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return f(G,n,m,0,k,dp)%MOD;
    }
};