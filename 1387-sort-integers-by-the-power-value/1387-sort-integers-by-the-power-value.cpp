class Solution {
public:
    int getKth(int lo, int hi, int k) {
        multimap<int,int>res;
        for(int i=lo;i<=hi;i++){
            res.insert({power(i),i});
        }
        auto it=res.begin();
        k--;
        while(k--){
            it++;
        }
        return it->second;
    }
    int power(int n){
        if(n<1)return 0;
        if(n==1)return 1;
        int steps=0;
        if(n&1)steps=1+power(n*3+1);
        else steps=1+power(n/2);
        return steps;
    }
};