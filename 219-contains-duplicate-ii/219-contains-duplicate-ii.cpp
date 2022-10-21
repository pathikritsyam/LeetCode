class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& A, int k) {
        /*for(int i=0,c=1;c<k&&i<A.size();c++){
            if(A[i]==A[i+c])return true;
            if(c==k){
                c=1;
                i++;
            }
        }
        return false;*/
        unordered_map<int,int>um;
        for(int i=0;i<A.size();i++)
        {
            if(um.find(A[i])!=um.end())
            {
                if(i-um[A[i]]<=k)
                    return true;
                else
                    um[A[i]]=i;
            }
            else
                um[A[i]]=i;
        }
        return false;
    }
};