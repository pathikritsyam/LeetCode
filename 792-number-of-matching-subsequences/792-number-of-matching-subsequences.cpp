struct Node{
    Node* links[26];
    int cntEndWith=0;
};
class Trie{
public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->links[word[i]-'a'])node->links[word[i]-'a']=new Node();
            node=node->links[word[i]-'a'];
        }
        (node->cntEndWith)++;
    }
    int dfs(Node* node,string &s, int idx,vector<int>pos[]){
        int res=0;
        for(int i=0;i<26;i++){
            if(node->links[i]){
                int newIdx=upper_bound(pos[i].begin(),pos[i].end(),idx)-pos[i].begin();
                if(newIdx==pos[i].size())continue;
                res+=dfs(node->links[i],s,pos[i][newIdx],pos);
            }
        }
        return res+node->cntEndWith;
    }
};
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        Trie* trie=new Trie();
        for(auto &it:words){
            trie->insert(it);
        }
        vector<int>pos[26];
        for(int i=0;i<s.length();i++){
            pos[s[i]-'a'].push_back(i);
        }
        return trie->dfs(trie->root,s,-1,pos);
    }
};