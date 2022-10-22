class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>h;
        int n=s.length(),m=t.length();
        for(auto c:t)
            h[c]++;
        int i=0,I=0,J=0;
        string res="";
        for(int j=1;j<=n;j++){
            m-=h[s[j-1]]>0;
            h[s[j-1]]--;
            if(m==0){
                while (i<j && h[s[i]]<0){
                    h[s[i]]++;
                    i++;
                }
                if(J==0 || j-i<=J-I)I=i,J=j;
            }
        }
        return s.substr(I,J-I);
    }
};
//S[I...J]