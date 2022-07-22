struct Node{
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};
class Trie {
    private: Node *root; 
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0;i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        }
        node->setEnd(); 
    }
    bool checkIfAllPrefixExists(string word) {
        Node *node = root;
        bool flag = true; 
        for(int i = 0;i<word.size() && flag;i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]); 
                flag = flag & node->isEnd(); 
            }
            else {
                return false; 
            } 
        }
        return flag; 
    }
};
class Solution{
public:
    string longestWord(vector<string>& words) {
        Trie* trie=new Trie();
        for(auto it:words){
            trie->insert(it);
        }
        string longest="";
        for(auto it:words){
            if(trie->checkIfAllPrefixExists(it)){
                if(longest.length()<it.length())longest=it;
                else if(longest.length()==it.length()&&it<longest)longest=it;
            }
        }
        return longest;
    }
};