//Since normal backtracking with dfs gave TLE, we use dijkstras algorithm in a modified way.
class Solution {
public:
    int directions[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<int>>diffmat(row,vector<int>(col,1e9));
        diffmat[0][0]=0;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;//priority que in order of differenced bwtween two matrix point(min-heap)
        vector<vector<int>>vis(row,vector<int>(col,0));
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff=pq.top().first;
            int x=pq.top().second[0];
            int y=pq.top().second[1];
            pq.pop();
            vis[x][y]=1;
            if(x==row-1&&y==col-1)return diff;
            for(int i=0;i<4;i++){
                int adjX=x+directions[i][0];
                int adjY=y+directions[i][1];
                if(isValid(adjX,adjY,row,col)&&vis[adjX][adjY]!=1){
                    int curDiff=abs(heights[adjX][adjY]-heights[x][y]);
                    int maxDiff=max(curDiff,diffmat[x][y]);
                    if(diffmat[adjX][adjY]>maxDiff){
                        diffmat[adjX][adjY]=maxDiff;
                        pq.push({maxDiff,{adjX,adjY}});
                    }
                }
            }
        }
        return diffmat[row-1][col-1];
    }
    bool isValid(int x,int y, int row,int col){
        return x>=0&&x<row&&y>=0&&y<col;
    }
};