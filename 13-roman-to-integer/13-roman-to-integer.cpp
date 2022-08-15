class Solution {
public:
    int romanToInt(string s) {
        vector<int>hash(26,0);
        hash['I'-'A']=1;
        hash['V'-'A']=5;
        hash['X'-'A']=10;
        hash['L'-'A']=50;
        hash['C'-'A']=100;
        hash['D'-'A']=500;
        hash['M'-'A']=1000;
        int res=hash[s.back()-'A'];
        for(int i=0;i<s.length()-1;i++){
            if(hash[s[i]-'A']<hash[s[i+1]-'A'])res-=hash[s[i]-'A'];
            else res+=hash[s[i]-'A'];
        }
        return res;
    }
};
//IV-4
//VI-6
//IIVI
//1+1+5+1=8
//1+4+1=6