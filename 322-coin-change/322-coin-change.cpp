class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0)prev[j]=j/coins[0];
            else prev[j]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int not_take=prev[j];
                int take=1e9;
                if(coins[i]<=j)take=1+curr[j-coins[i]];
                curr[j]= min(take,not_take);
            }
            prev=curr;
        }
        int res= prev[amount];
        if(res>=1e9)return -1;
        return res;
    }
};