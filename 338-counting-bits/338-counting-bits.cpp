class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i&(i-1)]+1;
        }
        return dp;
    }
};
//0 1 1 2 
//100 & 101->4