class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1e9,mini=1e9,max_ind=-1,min_ind=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi)maxi=nums[i],max_ind=i;
            if(nums[i]<mini)mini=nums[i],min_ind=i;
        }
        int len=abs(max_ind-min_ind);
        int dell,delr,delb;
        delb=n-len+1;
        dell=max(max_ind,min_ind)+1;
        delr=n-min(max_ind,min_ind);
        return min(delb,min(dell,delr));
    }
};