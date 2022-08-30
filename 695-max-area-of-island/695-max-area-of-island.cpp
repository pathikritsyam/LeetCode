class Solution {
public:
    int count;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0,count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid,count);
                    area=max(count,area);
                    count=0;
                }
            }
        }
        return area;
    }
    void dfs(int i,int j,vector<vector<int>>&grid,int &area){
        grid[i][j]=0;
        area++;
        if(i>0&&grid[i-1][j]==1)dfs(i-1,j,grid,area);
        if(j>0&&grid[i][j-1]==1)dfs(i,j-1,grid,area);
        if(i<grid.size()-1&&grid[i+1][j]==1)dfs(i+1,j,grid,area);
        if(j<grid[0].size()-1&&grid[i][j+1]==1)dfs(i,j+1,grid,area);
    }
};