class Solution {
public:
    vector<int> twoSum(vector<int>&nums,int target){
        unordered_map<int,int>hash;
        for(int num=0;num<nums.size();num++){
            int to_find=target-nums[num];
            if(hash.find(to_find)!=hash.end()){
                return {hash[to_find],num};
            }
            hash[nums[num]]=num;
        }
        return {};
    }
};
//2-0 7-1 11-2 15-3
//