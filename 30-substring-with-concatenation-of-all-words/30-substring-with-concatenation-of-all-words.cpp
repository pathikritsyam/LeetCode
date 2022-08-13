class Solution {
public:
    unordered_map<string,int>hash;
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength=words[0].length();
        int k=words.size();
        int concat=wordLength*k;
        for(string word:words){
            hash[word]++;
        }
        vector<int>res;
        for(int i=0;i<s.length()-concat+1;i++){
            unordered_map<string,int>duplicate=hash;
            for(int j=i;j<i+concat;j+=wordLength){
                if(duplicate[s.substr(j,wordLength)]>0)duplicate[s.substr(j,wordLength)]--;
            }
            bool flag=true;
            for(auto j:duplicate){
                if(j.second!=0){
                    flag=false;
                    break;
                }
            }
            if(flag)res.push_back(i);
        }
        return res;
    }
};
// "barfoothefoobarman"
//words = ["foo","bar"]
//concat=foobar
//1,1,0..1..2,0,0,1...
