class Solution {
public:
    vector<int> findOriginalArray(vector<int>& C) {
        if(C.size()&1)return {};
        vector<int>A,res;
        unordered_map<int,int>k;
        for(int i:C)
            k[i]++;
        for(auto i:k)
            A.push_back(i.first);
        sort(A.begin(),A.end(),[](const int &a,const int &b){return abs(a)<abs(b);});
        for(int i:A){
            if(k[i]>k[2*i])return {};
            for(int j=0;j<k[i];j++,k[2*i]--)
                res.push_back(i);
        }
        return res;
    }
};