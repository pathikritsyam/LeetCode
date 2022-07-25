class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        for(int i=0;i<=2*k;i++)dp[n][i]=0;
        for(int i=0;i<=n;i++)dp[i][2*k]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=2*k-1;j>=0;j--){
                if(j&1){
                    dp[i][j]=max(prices[i]+dp[i+1][j+1],dp[i+1][j]);
                }
                else{
                    dp[i][j]=max(-prices[i]+dp[i+1][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};