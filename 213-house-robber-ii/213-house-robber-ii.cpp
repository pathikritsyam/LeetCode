class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n+1,-1),dp2(n+1,-1);
        if(n==1)return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(f(n-2,temp1,dp1),f(n-2,temp2,dp2));
    }
    int f(int i,vector<int>&nums,vector<int>&dp){
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int rob=nums[i]+f(i-2,nums,dp);
        int dontrob=f(i-1,nums,dp);
        return dp[i]=max(rob,dontrob);
    }
};