class Solution {
    typedef long long ll;
public:
    long long countSubarrays(vector<int>& A, int minK, int maxK) {
        ll jmin=-1,jmax=-1,jbad=-1,res=0;
        for(int i=0;i<A.size();i++){
            if(A[i]<minK||A[i]>maxK)jbad=i;
            if(A[i]==minK)jmin=i;
            if(A[i]==maxK)jmax=i;
            res+=max(0LL,min(jmin,jmax)-jbad);
        }
        return res;
    }
};