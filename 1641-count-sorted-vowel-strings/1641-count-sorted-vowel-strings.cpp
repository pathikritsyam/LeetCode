class Solution {
public:
    int countVowelStrings(int n) {
        int dp[6][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=4;i>=0;i--){
            for(int j=1;j<=n;j++){
                int take=1+dp[i][j-1];
                int not_take=dp[i+1][j];
                dp[i][j]= take+not_take;
            }
        }
        return dp[0][n]-dp[0][n-1];
    }
};
