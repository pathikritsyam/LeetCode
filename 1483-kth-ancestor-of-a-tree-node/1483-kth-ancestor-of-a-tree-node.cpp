class TreeAncestor {
    vector<vector<int>>up;
public:
    int LOG=20;
    TreeAncestor(int n, vector<int>& parent) {
        up=vector<vector<int>>(n,vector<int>(LOG));
        //up[v][j]= 2^jth ancestor
        //setting up first ancestor
        for(int v=0;v<n;v++)up[v][0]=parent[v];
        for(int j=1;j<LOG;j++){
            for(int v=0;v<n;v++){
                if(up[v][j-1]==-1){
                    up[v][j]=-1;
                }
                else{
                    up[v][j]=up[up[v][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<LOG;i++){
            if(k&(1<<i)){
                node=up[node][i];
                if(node==-1)return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */