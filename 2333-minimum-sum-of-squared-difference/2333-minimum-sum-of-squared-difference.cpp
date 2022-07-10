class Solution {
public:
    const int N=1e5;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>diff(N+1,0);
        for(int i=0;i<nums1.size();i++){
            diff[abs(nums1[i]-nums2[i])]++;
        }
        int k=k1+k2;
        for(int i=N;i>0;i--){
            if(diff[i]==0)continue;
            if(k>=diff[i]){
                diff[i-1]+=diff[i];
                k-=diff[i];
                diff[i]=0;
            }
            else{
                diff[i-1]+=k;
                diff[i]-=k;
                k=0;
                break;
            }
        }
        long long int res=0;
        for(long long i=1;i<=N;i++){
            if(diff[i]>0)res+=i*i*diff[i];
        }
        return res;
    }
};