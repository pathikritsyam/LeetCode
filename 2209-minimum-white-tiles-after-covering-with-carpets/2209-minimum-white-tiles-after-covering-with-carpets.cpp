class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n=floor.size(),nc=numCarpets;
        vector<int>suffix(n);
        vector<vector<int>>dp(n,vector<int>(nc+1,-1));
        suffix[0]=(floor[0]=='1');
        for(int i=1;i<n;i++){
            suffix[i]+=suffix[i-1]+(floor[i]=='1');
        }
        return f(n-1,nc,suffix,carpetLen,floor,dp);
    }
    int f(int i,int j,vector<int>&suffix,int carpetLen,string &floor,vector<vector<int>>&dp){
        if(i<0)return 0;
        if(j==0)return suffix[i];
        if(dp[i][j]!=-1)return dp[i][j];
        int take=f(i-carpetLen,j-1,suffix,carpetLen,floor,dp);
        int not_take=floor[i]-'0'+f(i-1,j,suffix,carpetLen,floor,dp);
        return dp[i][j]=min(take,not_take);
    }
};