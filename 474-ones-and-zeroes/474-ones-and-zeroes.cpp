class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        vector<vector<vector<int>>>dp(l,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return f(l-1,m,n,strs,dp);
    }
    int f(int i,int m,int n,vector<string>&strs,vector<vector<vector<int>>>&dp){
        int zero=count(strs[i].begin(),strs[i].end(),'0');
        int ones=count(strs[i].begin(),strs[i].end(),'1');
        if(i==0){
            if((m>=zero)&&(n>=ones))return 1;
            return 0;
        }
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int dont_take=f(i-1,m,n,strs,dp);
        int take=0;
        if((m>=zero)&&(n>=ones))take=1+f(i-1,m-zero,n-ones,strs,dp);
        // else if(m>=zero)take=f(i-1,m-zero,n,str);
        // else if(n>=ones)take=f(i-1,m,n-ones,str);
        return dp[i][m][n]=max(take,dont_take);
    }
};