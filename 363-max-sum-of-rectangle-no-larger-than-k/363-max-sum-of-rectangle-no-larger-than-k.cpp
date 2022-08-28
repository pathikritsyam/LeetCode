class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row=matrix.size(),col=matrix[0].size(),res=-1e9;
        for(int l=0;l<col;l++){
            vector<int>sum(row,0);
            for(int r=l;r<col;r++){
                for(int i=0;i<row;i++){
                    sum[i]+=matrix[i][r];
                }
                set<int>s={0};
                int cur_sum=0;
                for(int i:sum){
                    cur_sum+=i;
                    auto it=s.lower_bound(cur_sum-k);
                    if(it!=s.end())res=max(res,cur_sum-*it);
                    s.insert(cur_sum);
                }
            }
        }
        return res;
    }
};