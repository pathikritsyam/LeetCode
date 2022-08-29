class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs(i,j,grid);
                }
            }
        }
        return res;
    }
    void dfs(int i,int j,vector<vector<char>>&grid){
        // cout<<i<<" "<<j<<"\n";
        grid[i][j]='0';
        if(i<grid.size()-1&&grid[i+1][j]=='1')dfs(i+1,j,grid);
        if(j<grid[0].size()-1&&grid[i][j+1]=='1')dfs(i,j+1,grid);
        if(i>0&&grid[i-1][j]=='1')dfs(i-1,j,grid);
        if(j>0&&grid[i][j-1]=='1')dfs(i,j-1,grid);
    }
};