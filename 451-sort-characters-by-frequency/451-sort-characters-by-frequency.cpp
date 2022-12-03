class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>hash;
        string res="";
        for(auto c:s){
            hash[c]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i:hash)
            pq.push({i.second,i.first});
        while(!pq.empty()){
            int a=pq.top().first;
            char b=pq.top().second;
            for(int i=0;i<a;i++)
                res+=b;
            pq.pop();
        }
        return res;
    }
};