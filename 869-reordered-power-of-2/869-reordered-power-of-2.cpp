class Solution {
public:
    vector<string>res;
    bool reorderedPowerOf2(int n) {
        vector<long long>dp(30,0);
        for(int i=0;i<30;i++)dp[i]=1ll<<i;
        string s=to_string(n);
        permutations(s,0,s.length()-1);
        for(auto i:res){
            int j=-1;
            if(i[0]!='0')j=stoi(i);
            if(find(dp.begin(),dp.end(),j)!=dp.end())return true;
        }
        return false;
    }
    void permutations(string s,int l,int r){
        if(l==r){
            res.push_back(s);
        }
        for(int i=l;i<=r;i++){
            swap(s[l],s[i]);
            permutations(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
};
//1->2->4->8->16->32
//123
//231
//312