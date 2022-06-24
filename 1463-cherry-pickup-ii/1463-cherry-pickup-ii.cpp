//Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        for(int j1=0;j1<=m-1;j1++){
            for(int j2=0;j2<=m-1;j2++){
                if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
                else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int dj[]={-1,0,1};
                    int maxi=-1e8;
                    for(int dj1:dj){
                        for(int dj2:dj){
                            if(j1+dj1>=0&&j1+dj1<m&&j2+dj2>=0&&j2+dj2<m){
                                if(j1==j2) maxi=max(maxi,grid[i][j1]+dp[i+1][j1+dj1][j2+dj2]);
                                else maxi=max(maxi,grid[i][j2]+grid[i][j1]+dp[i+1][j1+dj1][j2+dj2]);
            }
                            // else{
                            //     maxi=max(maxi,-1e9);
                            // }
                        }
        }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};