class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        set<string>s(wordList.begin(),wordList.end());
        q.push(beginWord);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            level++;
            for(int i=0;i<n;i++){
                string currentString=q.front();
                q.pop();
                if(currentString==endWord)return level;
                vector<string>neighbor=neighbors(currentString);
                for(string word:neighbor){
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push(word);
                    }
                }
            }
        }
        return 0;
    }
    vector<string>neighbors(string s){
        vector<string>neighbor;
        for(int i=0;i<s.length();i++){
            for(char c='a';c<='z';c++){
                string newWord=s.substr(0,i)+c+s.substr(i+1);
                neighbor.push_back(newWord);
            }
        }
        return neighbor;
    }
};
//graph question
//consider a vector having all words differing from that single given word by 1 character.
//BFS to find the shortest path to endWord
//return 0 if BFS cant find endWord
