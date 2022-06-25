class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum&1)return false;
        int target=sum/2;
        vector<bool>prev(sum/2+1,false),curr(sum/2+1,false);
        prev[0]=true;curr[0]=true;
        if(nums[0]<=target)prev[nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool dont_take=prev[j];
                bool take=false;
                if(nums[i]<=j)take=prev[j-nums[i]];
                curr[j]=take+dont_take;
            }
            prev=curr;
        }
        return prev[sum/2];
    }
};