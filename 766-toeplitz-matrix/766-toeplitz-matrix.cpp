class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& M) {
        for(int i=1;i<M.size();i++){
            for(int j=1;j<M[0].size();j++){
                if(M[i][j]!=M[i-1][j-1])return false;
            }
        }
        return true;
    }
};
//[[53,64,90,98,34]
//[91,53,64,90,98]
//[17,91,53,64,0]