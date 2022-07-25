class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size(),profit;
        vector<vector<int>>ahead(2,vector<int>(k+1,0)),cur(2,vector<int>(k+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
                ahead[j][0]=0;
            }
        }
        for(int j=0;j<2;j++){
            for(int cap=0;cap<=k;cap++){
                ahead[j][cap]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy){
                        profit=max(-prices[i]+ahead[0][cap],ahead[1][cap]);
                    }
                    else{
                        profit=max(prices[i]+ahead[1][cap-1],ahead[0][cap]);
                    }
                    cur[buy][cap]=profit;
                }
                ahead=cur;
            }
        }
        return ahead[1][k];
    }
};