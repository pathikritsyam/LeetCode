class Solution {
public:
    vector<int>price;
    int profit;
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        price=prices;
        return f(0,1,dp);
    }
    int f(int i,int buy,vector<vector<int>>&dp){
        if(i==price.size()){
            return 0;
        }
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            profit=max(-price[i]+f(i+1,0,dp),f(i+1,1,dp));
        }
        else{
            profit=max(price[i]+f(i+1,1,dp),f(i+1,0,dp));
        }
        return dp[i][buy]=profit;
    }
};
//either buy or sell
//in each either take or not take