class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
    int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(i==n)return 0;
        if(dp[i][j+1]!=-1)return dp[i][j+1];
        int not_take=f(i+1,j,nums,dp);
        int take=0;
        if(j==-1||nums[i]>nums[j]){
            take=1+f(i+1,i,nums,dp);
        }
        int len=max(take,not_take);
        return dp[i][j+1]=len;
    }
};