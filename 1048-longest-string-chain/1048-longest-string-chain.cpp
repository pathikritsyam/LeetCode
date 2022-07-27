class Solution {
public:
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]))dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    bool compare(string &a,string &b){
        if(a.size()!=b.size()+1)return false;
        int first=0,second=0;
        while(first<a.size()){
            if(a[first]==b[second]){
                first++;
                second++;
            }
            else first++;
        }
        if(first==a.size()&&second==b.size())return true;
        return false;
    }
};
// ab
//   ^
// a
// ^