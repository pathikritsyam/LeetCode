class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++){
            bool f=true;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    f=false;
                    break;
                }
            }
            dp[0][j]=f;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?')dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};
// abcdef
// ab*f