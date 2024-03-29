class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // int res=1e9;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++)pq.push(matrix[i][j]);
        }
        k--;
        while(k--)pq.pop();
        return pq.top();
    }
};