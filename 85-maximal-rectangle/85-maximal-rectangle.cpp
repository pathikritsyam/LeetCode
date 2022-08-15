class Solution {
public:
    int histogram(vector<int>heights){
        stack<int>st;
        st.push(-1);
        int maxArea=0;
        for(int i=0;i<heights.size();i++)
        {
            while(st.top()!=-1&&heights[st.top()]>=heights[i]){
                int cur_height=heights[st.top()];
                st.pop();
                int cur_width=i-st.top()-1;
                maxArea=max(maxArea,cur_height*cur_width);
            }
            st.push(i);
        }
        while(st.top()!=-1){
            int cur_height=heights[st.top()];
            st.pop();
            int cur_width=heights.size()-st.top()-1;
            maxArea=max(maxArea,cur_height*cur_width);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int maxArea=0;
        vector<int>dp(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[j]=matrix[i][j]=='1'?dp[j]+1:0;
            }
            maxArea=max(maxArea,histogram(dp));
        }
        return maxArea;
    }
};
//1 0 1 0 0
//2 0 2 1 1