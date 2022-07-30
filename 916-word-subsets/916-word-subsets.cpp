class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>a(26,0),c(26,0);
        for(string word:words2){
            c=counter(word);
            for(int i=0;i<26;i++){
                a[i]=max(a[i],c[i]);
            }
        }
        vector<string>res;
        for(string word:words1){
            vector<int>b=a;
            for(char c:word){
                if(b[c-'a']>0)b[c-'a']--;
            }
            if(count(b.begin(),b.end(),0)==26)res.push_back(word);
        }
        return res;
    }
    vector<int>counter(string w){
        vector<int>count(26,0);
        for(char c:w){
            count[c-'a']++;
        }
        return count;
    }
};
// amazon
// aazb
// 00000....00000
