class Solution {
public:
    string longestPalindrome(string s) {
        string t="#";
        for(int i=0;i<s.length();i++)t=t+s[i]+"#";
        t="^"+t+"$";
        vector<int>p(t.length(),0);
        int c=0,r=0;
        for(int i=1;i<t.length()-1;i++){
            int mirr=2*c-i;
            if(i<r)p[i]=min(r-i,p[mirr]);
            while(t[i+(1+p[i])]==t[i-(1+p[i])])p[i]++;
            if(i+p[i]>r){
                c=i;
                r=i+p[i];
            }
        }
        int m=0,index=-1;
        for(int i=0;i<p.size();i++){
            if(p[i]>m){
                m=p[i];
                index=i;
            }
        }
        return s.substr((index-m-1)/2,m);
        // return t;
    }
};