class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>dp(values.size(),vector<int>(values.size(),-1));
        return f(1,values.size()-1,values,dp);
    }
    int f(int i,int j,vector<int>&values,vector<vector<int>>&dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=1e9;
        for(int k=i;k<j;k++){
            int step=values[i-1]*values[k]*values[j]+f(i,k,values,dp)+f(k+1,j,values,dp);
            mini= min(mini,step);
        }
        return dp[i][j]=mini;
    }
};
//0 1 2 3
//3 7 4 5
//7 4 4 5 