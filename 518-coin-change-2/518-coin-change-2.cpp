class Solution {
public:
    int change(int amount, vector<int>& coins) {
        long long n=coins.size();
        vector<long long>prev(amount+1,0);
        vector<long long>curr(amount+1,0);
        for(long long j=0;j<=amount;j++){
            prev[j]=(j%coins[0]==0);
        }
        for(long long i=1;i<n;i++){
            for(long long j=0;j<=amount;j++){
                long long dont_take=prev[j];
                long long take=0;
                if(coins[i]<=j)take=curr[j-coins[i]];
                curr[j]=take+dont_take;
            }
            prev=curr;
        }
        long long res=prev[amount];
        if(res>=INT_MAX)return 0;
        return res;
    }
};