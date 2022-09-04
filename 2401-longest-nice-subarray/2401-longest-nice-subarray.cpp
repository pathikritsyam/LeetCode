class Solution {
public:
    int longestNiceSubarray(vector<int>& A) {
        int AND=0,i=0,res=0;
        for(int j=0;j<A.size();j++){
            while((AND&A[j])>0)
                AND^=A[i++];
            AND|=A[j];
            res=max(res,j-i+1);
        }
        return res;
    }
};