class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0,res=0,count=0;;
        
        queue<vector<int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)q.push({i,j,0}),cnt++;
                else if(grid[i][j]==1)cnt++;
            }
        }
        while(!q.empty()){
            count++;
            int i=q.front()[0],j=q.front()[1],wt=q.front()[2];
            q.pop();
            res=wt;
            // if(grid[i][j]==0)continue;
            if(i+1<m&&grid[i+1][j]==1){
                q.push({i+1,j,wt+1});
                grid[i+1][j]=2;
            }
            if(i-1>=0&&grid[i-1][j]==1){
                q.push({i-1,j,wt+1});
                grid[i-1][j]=2;
            }
            if(j+1<n&&grid[i][j+1]==1){
                q.push({i,j+1,wt+1});
                grid[i][j+1]=2;
            }
            if(j-1>=0&&grid[i][j-1]==1){
                q.push({i,j-1,wt+1});
                grid[i][j-1]=2;
            }
        }
        if(count!=cnt)return -1;
        return res;
    }
};
//1 2
//0,1,0 