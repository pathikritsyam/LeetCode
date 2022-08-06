class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(n-1,0,0,s,k,dp);
    }
    int f(int i,int size,int sum,string &s,int k,vector<vector<int>>&dp){
        if(i<0)return 0;
        if(dp[i][size]!=-1)return dp[i][size];
        int not_take=f(i-1,size,sum,s,k,dp);
        int take=0;
        if((sum + (s[i]-'0')*pow(2,size)) <= k){
            take=1+f(i-1,size+1,(sum + (s[i]-'0')*pow(2,size)),s,k,dp);
        }
        return dp[i][size]=max(take,not_take);
    }
};
//1001010
//0101001