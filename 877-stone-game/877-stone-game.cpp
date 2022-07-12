class Solution {
public:
    int dp[501][501];
    bool stoneGame(vector<int>& piles) {
        int l=0,r=piles.size()-1,sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=r;i++)sum+=piles[i];
        int alice=f(l,r,piles);
        return alice>(sum-alice);
    }
    int f(int l,int r,vector<int>&piles){
        if(l>=r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int left=piles[l]+max(f(l+2,r,piles),f(l+1,r-1,piles));
        int right=piles[r]+max(f(l,r-2,piles),f(l+1,r-1,piles));
        return dp[l][r]=max(left,right);
    }
};