class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res= f(n-1,amount,coins,dp);
        if(res==1e9)return -1;
        return res;
    }
    int f(int i,int j,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0){
            if(j%coins[i]==0)return j/coins[i];
            return 1e9;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int not_take=f(i-1,j,coins,dp);
        int take=1e9;
        if(coins[i]<=j)take=1+f(i,j-coins[i],coins,dp);
        return dp[i][j]= min(take,not_take);
    }
};