class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum&1)return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return f(n-1,sum/2,nums,dp);
    }
    bool f(int n,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0)return true;
        if(n==0) return (target==nums[n]);
        if(dp[n][target]!=-1)return dp[n][target];
        bool dont_take=f(n-1,target,nums,dp);
        bool take=false;
        if(nums[n]<=target)take=f(n-1,target-nums[n],nums,dp);
        return dp[n][target]=take+dont_take;
    }
};