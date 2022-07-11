class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>lft(n),rgt(n),res;
        lft[0]=nums[0];
        for(int i=1;i<n;i++){
            lft[i]=nums[i];
            if(i%k!=0){
                lft[i]=max(lft[i-1],lft[i]);
            }
        }
        rgt[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            rgt[i]=nums[i];
            if(i%k!=k-1){
                rgt[i]=max(rgt[i+1],rgt[i]);
            }
        }
        for(int i=0;i<n-k+1;i++){
            res.push_back(max(rgt[i],lft[i+k-1]));
        }
        return res;
    }
};
//Soln Using Dequeue
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         deque<int>dq;
//         vector<int>res;
//         for(int i=0;i<nums.size();i++){
//             if(!dq.empty()&&dq.front()==(i-k))dq.pop_front();
//             while(!dq.empty()&&nums[dq.back()]<nums[i])dq.pop_back();
//             dq.push_back(i);
//             if(i>=k-1)res.push_back(nums[dq.front()]);
//         }
//         return res;
//     }
// };