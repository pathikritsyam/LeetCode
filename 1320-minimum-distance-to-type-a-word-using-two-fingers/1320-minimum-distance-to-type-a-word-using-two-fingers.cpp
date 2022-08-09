class Solution {
public:
    int findPos(char c){
        return c-'A';
    }
    int findDist(int from,int to){
        if(from==26)return 0;
        int r1=from/6;
        int c1=from%6;
        int r2=to/6;
        int c2=to%6;
        return abs(r1-r2)+abs(c1-c2);
    }
    int solver(int index,int finger1,int finger2,string word,vector<vector<vector<int>>>&dp){
        if(index==word.size())return 0;
        if(dp[index][finger1][finger2]!=-1)return dp[index][finger1][finger2];
        int newPos=findPos(word[index]);
        int cost1=findDist(finger1,newPos);
        int cost2=findDist(finger2,newPos);
        int move_finger1=cost1+solver(index+1,newPos,finger2,word,dp);
        int move_finger2=cost2+solver(index+1,finger1,newPos,word,dp);
        return dp[index][finger1][finger2]=min(move_finger1,move_finger2);
    }
    int minimumDistance(string word) {
        vector<vector<vector<int>>>dp(word.size()+1,vector<vector<int>>(27,vector<int>(27,-1)));
        return solver(0,26,26,word,dp);
    }
};
//row=(ch-'A')%6
//col=(ch-'A')/6