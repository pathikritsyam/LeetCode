class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>>dir{{0,1},{1,0},{0,-1},{-1,0}};
        int row=matrix.size(),col=matrix[0].size();
        vector<int>res;
        if(!row||!col)return res;
        vector<int>move{col,row-1};
        int rowi=0,coli=-1,idir=0;
        while(move[idir%2]!=0){
            for(int i=0;i<move[idir%2];++i){
                rowi+=dir[idir][0];
                coli+=dir[idir][1];
                res.push_back(matrix[rowi][coli]);
            }
            move[idir%2]--;
            idir++;idir%=4;
        }
        return res;
    }
};