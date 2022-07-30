class Solution {
public:
    int longestValidParentheses(string s) {
        s="#"+s;
        int n=s.size(),res=0;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            if(s[i]==')'&&s[i-1]=='(')dp[i]=dp[i-2]+2;
            else if(s[i]==')'&&s[i-1]==')'){
                if(s[i-dp[i-1]-1]=='(')dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2;
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
//  0123456789
// ")((()))())"
//  0000246080    