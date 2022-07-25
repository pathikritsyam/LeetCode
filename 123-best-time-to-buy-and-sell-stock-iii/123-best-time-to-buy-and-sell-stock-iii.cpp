class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),profit;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for(int j=0;j<2;j++){
            for(int cap=0;cap<=2;cap++){
                dp[n][j][cap]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<3;cap++){
                    if(buy){
                        profit=max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                    }
                    else{
                        profit=max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }
                    dp[i][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};