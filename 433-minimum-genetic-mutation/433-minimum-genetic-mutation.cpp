class Solution {
public:
    int minMutation(string start, string end, vector<string>& B) {
        queue<string>q;
        unordered_set<string>s;
        q.push(start);
        s.insert(start);
        int d=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string node=q.front();
                q.pop();
                if(node==end)
                    return d;
                for(char c:"ACGT"){
                    for(int j=0;j<node.size();j++){
                        string neighbor=node;
                        neighbor[j]=c;
                        if(s.count(neighbor)==0&&find(B.begin(),B.end(),neighbor)!=B.end()){
                            q.push(neighbor);
                            s.insert(neighbor);
                        }
                    }
                }
            }
            d++;
        }
        return -1;
    }
};