class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),res=0,mini=prices[0];
        int dp[n];dp[0]=0;
        for(int i=1;i<n;i++){
            dp[i]=prices[i]-mini;
            mini=min(mini,prices[i]);
            res=max(res,dp[i]);
        }
        return res;
    }
};