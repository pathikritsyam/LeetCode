class Solution {
public:
    vector<int>price;
    int profit;
    int maxProfit(vector<int>& prices) {
        //vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        vector<int>prev(2),cur(2);
        int n=prices.size();
        prev[0]=prev[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    profit=max(-prices[i]+prev[0],prev[1]);
                }
                else{
                    profit=max(prices[i]+prev[1],prev[0]);
                }
                cur[buy]=profit;
            }
            prev=cur;
        }
        return prev[1];
    }
};
//either buy or sell
//in each either take or not take