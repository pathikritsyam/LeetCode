class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(nums.size()-1,nums,dp);
    }
    int f(int i,vector<int>&nums,vector<int>&dp){
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int rob=nums[i]+f(i-2,nums,dp);
        int dontrob=f(i-1,nums,dp);
        return dp[i]=max(rob,dontrob);
    }
};