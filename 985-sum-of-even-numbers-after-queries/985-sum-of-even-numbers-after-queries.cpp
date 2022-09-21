class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& q) {
        vector<int>res;
        int s=0;
        for(auto i:A)if(i%2==0)s+=i;
        for(auto i:q){
            int val=i[0],index=i[1];
            if(!(A[index]&1))s-=A[index];
            A[index]+=val;
            if(A[index]%2==0)s+=A[index];
            res.push_back(s);
        }
        return res;
    }
};