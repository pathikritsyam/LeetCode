class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        int zero=count(strs[0].begin(),strs[0].end(),'0');
        int ones=count(strs[0].begin(),strs[0].end(),'1');
        vector<vector<vector<int>>>dp(l,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i=zero;i<=m;i++){
            for(int j=ones;j<=n;j++){
                dp[0][i][j]=1;
            }
        }
        for(int i=1;i<l;i++){
            int zero=count(strs[i].begin(),strs[i].end(),'0');
            int ones=count(strs[i].begin(),strs[i].end(),'1');
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int dont_take=0+dp[i-1][j][k];
                    int take=0;
                    if((j>=zero)&&(k>=ones))take=1+dp[i-1][j-zero][k-ones];
                    dp[i][j][k]=max(take,dont_take); 
                }
            }
        }
        return dp[l-1][m][n];
    }
};