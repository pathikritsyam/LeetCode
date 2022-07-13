class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length(),b=0;
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            if(s[i-1]=='a')dp[i]=min(dp[i-1]+1,b);
            else dp[i]=dp[i-1],b++;
        }
        return dp[n];
    }
};