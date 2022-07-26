class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int not_take=dp[i+1][j+1];
                int take=0;
                if(j==-1||nums[i]>nums[j]){
                    take=1+dp[i+1][i+1];
                }
                int len=max(take,not_take);
                dp[i][j+1]=len;
            }
        }
        return dp[0][0];
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