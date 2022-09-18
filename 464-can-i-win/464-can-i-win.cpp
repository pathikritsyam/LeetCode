class Solution {
public:
    vector<vector<int>>dp;
    int m,d;
    bool f(int mask,int p,int score){
        if(dp[p][mask]!=-1)return dp[p][mask];
        for(int i=0;i<m;i++){
            int cmask=1<<i;
            if((mask&cmask)==0)
                if(score+i+1>=d||(f(mask|cmask,p^1,score+i+1)==false))return dp[p][mask]=1;
        }
        return dp[p][mask]=0;
    }
    bool canIWin(int m, int d) {
        this->m=m;
        this->d=d;
        dp.resize(2,vector<int>(1<<m,-1));
        if(m*(m+1)/2<d)return false;
        return f(0,0,0);
    }
};