class Solution {
public:
    vector<int>res;
    int k;
    vector<int> numsSameConsecDiff(int n, int k) {
        this->k=k;
        for(int i=1;i<10;i++)
            dfs(n-1,i);
        return res;
    }
    void dfs(int n,int s){
        if(n==0)res.push_back(s);
        else{
            int ld=s%10;
            if(ld+k<=9)
                dfs(n-1,s*10+ld+k);
            if(k!=0 && ld-k>=0)
                dfs(n-1,s*10+ld-k);
        }
    }
};