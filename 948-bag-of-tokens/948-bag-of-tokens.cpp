class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int res=0,p=0,l=0,r=tokens.size()-1;
        while(l<=r){
            if(power>=tokens[l]){
                power-=tokens[l++];
                res=max(res,++p);
            }
            else if(p>0){
                p--;
                power+=tokens[r--];
            }
            else
                break;
        }
        return res;
    }
};