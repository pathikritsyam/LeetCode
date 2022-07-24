class Solution {
public:
    int countBit(int n){
        int res=0;
        for(int i=0;i<31;i++){
            if(n&(1<<i))res++;
        }
        return res;
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long n=nums.size(),res=0;
        long long cnt[30]={};
        unordered_set<int>s=unordered_set<int>(nums.begin(),nums.end());
        for(auto i:s){
            cnt[countBit(i)]++;
        }
        for(int i=1;i<30;i++){
            for(int j=1;j<30;j++){
                if(i+j>=k)res+=cnt[i]*cnt[j];
            }
        }
        return res;
    }
};