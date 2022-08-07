class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return f(1,n,nums,dp);
    }
    int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        int maxi=-1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<=j;k++){
            int points=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            maxi=max(maxi,points);
        }
        return dp[i][j]=maxi;
    }
};
//1 3 1 5 8 1