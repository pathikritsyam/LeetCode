class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool>c(3,true);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]!=target[i][j])c[0]=false;
                if(mat[i][j]!=target[j][mat.size()-i-1])c[1]=false;
                if(mat[i][j]!=target[mat.size()-i-1][mat[0].size()-j-1])c[2]=false;
                if(mat[i][j]!=target[mat.size()-j-1][i])c[3]=false;
            }
        }
        return c[0]||c[1]||c[2]||c[3];
    }
};