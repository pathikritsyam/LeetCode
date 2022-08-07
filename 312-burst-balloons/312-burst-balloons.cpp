class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j)continue;
                int maxi=-1e9;
                for(int k=i;k<=j;k++){
                    int points=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                    maxi=max(maxi,points);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};
//1 3 1 5 8 1