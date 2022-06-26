class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        int zero=count(strs[0].begin(),strs[0].end(),'0');
        int ones=count(strs[0].begin(),strs[0].end(),'1');
        vector<vector<int>>prev(m+1,vector<int>(n+1,0));
        for(int i=zero;i<=m;i++){
            for(int j=ones;j<=n;j++){
                prev[i][j]=1;
            }
        }
        for(int i=1;i<l;i++){
            int zero=count(strs[i].begin(),strs[i].end(),'0');
            int ones=count(strs[i].begin(),strs[i].end(),'1');
            vector<vector<int>>curr(m+1,vector<int>(n+1,0));
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int dont_take=0+prev[j][k];
                    int take=0;
                    if((j>=zero)&&(k>=ones))take=1+prev[j-zero][k-ones];
                    curr[j][k]=max(take,dont_take); 
                }
            }
            prev=curr;
        }
        return prev[m][n];
    }
};