class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int i=0,res=0,k=1;
        for(int j=0;j<A.size();j++){
            if(A[j]==0)k--;
            while(k<0){
                if(A[i]==0)k++;
                i++;
            }
            res=max(res,j-i);
        }
        return res;
    }
};