class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return f(nums,target,dp);
    }
    int f(vector<int>&nums,int target,vector<int>&dp){
        if(target<0)return 0;
        if(target==0)return 1;
        if(dp[target]!=-1)return dp[target];
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(target>=nums[i])res+=f(nums,target-nums[i],dp);
        }
        return dp[target]=res;
    }
};