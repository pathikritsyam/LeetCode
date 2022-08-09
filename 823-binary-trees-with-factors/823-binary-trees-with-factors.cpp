class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int N=1e9+7;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>index;
        vector<long>dp(n,1);
        for(int i=0;i<n;i++){
            index[arr[i]]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int left=arr[j];
                    int right=arr[i]/left;
                    if(index.find(right)!=index.end()){
                        dp[i]=(dp[i]+(dp[j]*dp[index[right]]))%N;
                    }
                }
            }
        }
        int res=0;
        for(auto i:dp)res=(res+i)%N;
        return res%N;
    }
};
//2,3,6