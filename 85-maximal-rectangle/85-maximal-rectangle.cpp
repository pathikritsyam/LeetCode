class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        int maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=j==0?1:dp[i][j-1]+1;
                    int maxWidth=dp[i][j];
                    for(int k=i;k>=0;k--){
                        maxWidth=min(maxWidth,dp[k][j]);
                        maxArea=max(maxArea,maxWidth*(i-k+1));
                    }
                }
            }
        }
        return maxArea;
    }
};
//1 0 1 0 0
//1 0 1 2 3
//1 2 3 4 5
//1 0 0 1 0
//maxWidth=min(maxWidth,curWidth)
//curArea=maxWidth*(k+1);
//maxArea=max(maxArea,curArea)