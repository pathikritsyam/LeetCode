class Solution {
public:
    int n;
    vector<int>A;
    int dp[301][301];
    int dfs(int i,int d){
        if(dp[i][d]!=-1)return dp[i][d];
        if (d==1)return *max_element(A.begin()+i,A.end());
        int res=1e9,temp=-1e9;
        for(int j=i;j<n-d+1;j++){
            temp=max(temp,A[j]);
            res = min(res,dfs(j+1,d-1)+temp);
        }
        return dp[i][d]=res;
    }
    int minDifficulty(vector<int>& A, int d) {
        n=A.size();
        memset(dp,-1,sizeof dp);
        this->A=A;
        if(d>n)return -1;
        return dfs(0,d);
    }
};