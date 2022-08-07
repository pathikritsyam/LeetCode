class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        int dp[n][n];
        for(int i=0;i<n;i++)dp[i][i]=0;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int mini=1e9;
                for(int k=i;k<j;k++){
                    int step=values[i-1]*values[k]*values[j]+dp[i][k]+dp[k+1][j];
                    mini= min(mini,step);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][n-1];
    }
};
//0 1 2 3
//3 7 4 5
//7 4 4 5 