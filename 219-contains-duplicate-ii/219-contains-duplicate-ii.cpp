class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& A, int k) {
        unordered_map<int,int>mp;
        int n=A.size();
        for(int i=0;i<n;i++){
            if(mp.find(A[i])!=mp.end()&&i-mp[A[i]]<=k){
                return true;
            }
            mp[A[i]]=i;
        }
        return false;
    }
};