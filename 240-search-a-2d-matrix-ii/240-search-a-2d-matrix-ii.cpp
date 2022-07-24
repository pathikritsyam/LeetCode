class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),l,r;
        for(int i=0;i<m;i++){
            l=-1,r=n;
            while(l+1<r){
                int mid=l+(r-l)/2;
                if(matrix[i][mid]<target)l=mid;
                else r=mid;
            }
            if(r!=n&&matrix[i][r]==target)return true;
        }
        return false;
    }
};