class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        vector<vector<int>>pacific(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>atlantic(heights.size(),vector<int>(heights[0].size(),0));
        for(int i=0;i<heights.size();i++){
            dfs(i,0,pacific,heights);
            dfs(i,heights[0].size()-1,atlantic,heights);
        }
        for(int j=0;j<heights[0].size();j++){
            dfs(0,j,pacific,heights);
            dfs(heights.size()-1,j,atlantic,heights);
        }
        for(int i=0;i<heights.size();i++)
            for(int j=0;j<heights[0].size();j++)
                if(pacific[i][j]&&atlantic[i][j])ans.push_back({i,j});
        return ans;
    }
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&heights){
        vis[i][j]=1;
        if(i>0&&!vis[i-1][j]&&heights[i-1][j]>=heights[i][j])dfs(i-1,j,vis,heights);
        if(j>0&&!vis[i][j-1]&&heights[i][j-1]>=heights[i][j])dfs(i,j-1,vis,heights);
        if(i<heights.size()-1&&!vis[i+1][j]&&heights[i+1][j]>=heights[i][j])dfs(i+1,j,vis,heights);
        if(j<heights[0].size()-1&&!vis[i][j+1]&&heights[i][j+1]>=heights[i][j])dfs(i,j+1,vis,heights);
    }
};