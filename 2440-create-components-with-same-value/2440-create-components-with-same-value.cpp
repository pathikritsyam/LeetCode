class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<int>A;
    int c,val;
    int dfs(int v,int p){
        int sum=A[v];
        for(auto i:adj[v]){
            if(i!=p) sum+=dfs(i,v);
        }
        if(sum==val){
            c--;
            return 0;
        }
        return sum;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int res=0;
        A=nums;
        int n=nums.size();
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int sum=accumulate(A.begin(),A.end(),0);
        if(count(A.begin(),A.end(),A[0])==n)return n-1;
        for(int i=2;i<n;i++){
            if(sum%i)continue;
            c=i,val=sum/i;
            dfs(0,-1);
            if(c==0)res=max(res,i-1);
            c=sum/i,val=i;
            dfs(0,-1);
            if(c==0)res=max(res,sum/i-1);
        }
        return res;
    }
};