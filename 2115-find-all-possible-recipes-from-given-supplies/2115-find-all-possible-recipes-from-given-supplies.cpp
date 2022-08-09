class Solution {
public:
    unordered_map<string,vector<string>>adj;
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int>indegree;
        for(int i=0;i<ingredients.size();i++){
            for(string s:ingredients[i]){
                adj[s].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string>q;
        for(string s:supplies){
            q.push(s);
        }
        while(!q.empty())
        {
            string to_create=q.front();
            q.pop();
            for(string recipe:adj[to_create]){
                indegree[recipe]--;
                if(indegree[recipe]==0){
                    q.push(recipe);
                }
            }
        }
        vector<string>ans;
        for(auto i:indegree){
            if(i.second==0)ans.push_back(i.first);
        }
        return ans;
    }
};
//recipes