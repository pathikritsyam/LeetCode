class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int n=nums.size();
        if(nums.empty())return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int add = (nums[i]+nums[j])/2;
                if((target/2-add)<=INT_MIN/2||(target/2-add)>=INT_MAX/2)continue;
                int sum=target-nums[i]-nums[j];
                int l=j+1,r=n-1;
                while(l<r)
                {
                    int two_sum=nums[l]+nums[r];
                    if(two_sum<sum)l++;
                    else if(two_sum>sum)r--;
                    else{
                        vector<int>t(4);
                        t[0]=nums[i];
                        t[1]=nums[j];
                        t[2]=nums[l];
                        t[3]=nums[r];
                        res.push_back(t);
                        while(l<r && nums[l]==t[2])l++;
                        while(l<r && nums[r]==t[3])r--;
                    }
                }
                while(j+1<n-2 && nums[j+1]==nums[j])++j;
            }
            while(i+1<n-3 && nums[i+1]==nums[i])++i;
        }
        return res;
    }
};