class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int matrix[n][n],maxi=0;
        memset(matrix,0,sizeof(matrix));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>maxi)maxi=grid[i][j];
            }
            for(int j=0;j<n;j++){
                matrix[i][j]=maxi;
            }
            maxi=0;
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(grid[i][j]>maxi)maxi=grid[i][j];
            }
            for(int i=0;i<n;i++){
                matrix[i][j]=min(matrix[i][j],maxi);
            }
            maxi=0;
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res+=(matrix[i][j]-grid[i][j]);
            }
        }
        return res;
    }
};
//take a new mtrix and store min row and col of each element
//8 4 8 7
//7 4 7 7
//9 4 8 7
//3 3 3 3
//take the diff b/w this and original matrix and sum all of it
//5+4+0+3+5+0+2+0+0+2+2+4+3+0+2+3=35