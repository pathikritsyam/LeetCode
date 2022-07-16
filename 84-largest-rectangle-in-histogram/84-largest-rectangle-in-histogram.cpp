class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),res=0;
        vector<int>st;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||heights[st.back()]>heights[i])){
                int j=st.back();
                st.pop_back();
                res=max(res,heights[j]*(i-(st.empty()?0:(st.back()+1))));
            }
            st.push_back(i);
        }
        return res;
    }
};

// [4,2,0,3,2,5]
// 2,5