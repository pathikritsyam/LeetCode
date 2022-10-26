class Solution {
public:
    bool checkSubarraySum(vector<int>& A, int k) {
        int n=A.size();
        vector<int>pre(n+1);
        for(int i=1;i<=n;i++)
            pre[i]=pre[i-1]+A[i-1];
        unordered_set<int>s;
        s.insert(pre[0]%k);
        for(int i=2;i<=n;i++){
            s.insert(pre[i-2]%k);
            if(s.find(pre[i]%k)!=s.end())
                return true;
        }    
        return false;
    }
};