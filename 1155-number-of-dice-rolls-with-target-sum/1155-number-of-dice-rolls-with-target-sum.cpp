class Solution {
public:
    int mod=1e9+7;
    int dp[31][1001]={};
    int numRollsToTarget(int n, int k, int target,int res=0) {
        if(n==0||target<=0)return n==target;
        if(dp[n][target])return dp[n][target]-1;
        for(int i=1;i<=k;i++)
            res=(res+numRollsToTarget(n-1,k,target-i))%mod;
        dp[n][target]=res+1;
        return res;
    }
};