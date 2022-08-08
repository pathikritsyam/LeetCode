class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0,r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>&grid,int r,int c){
        int n=grid.size(),m=grid[0].size();
        grid[r][c]=0;
        if(r-1>=0&&grid[r-1][c]=='1')dfs(grid,r-1,c);
        if(r+1<n&&grid[r+1][c]=='1')dfs(grid,r+1,c);
        if(c-1>=0&&grid[r][c-1]=='1')dfs(grid,r,c-1);
        if(c+1<m&&grid[r][c+1]=='1')dfs(grid,r,c+1);
    }
};