class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>temp=matrix;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                temp[i][j]=matrix[j][i];
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                matrix[i][j]=temp[i][matrix[0].size()-j-1];
    }
};