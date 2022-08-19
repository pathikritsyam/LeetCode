class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>remaining,ending;
        for(int i:nums){
            remaining[i]++;
        }
        for(int i:nums){
            if(remaining[i]==0)continue;
            remaining[i]--;
            if(ending[i-1]>0){
                ending[i-1]--;
                ending[i]++;
            }
            else if(remaining[i+1]>0&&remaining[i+2]>0){
                remaining[i+1]--;
                remaining[i+2]--;
                ending[i+2]++;
            }
            else return false;
        }
        return true;
    }
};
//1 2 3 3 4 5 
//remaining[i] denotes the number of numbers remaining
//taken[i] denotes the number of subsequences till i
