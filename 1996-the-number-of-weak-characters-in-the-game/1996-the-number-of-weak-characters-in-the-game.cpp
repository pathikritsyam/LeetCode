class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int maxi=-1e9,cnt=0;
        sort(properties.begin(),properties.end(),[](const vector<int>&a, const vector<int>&b){
            if(a[0]!=b[0])return a[0]>b[0];
            return a[1]<b[1];
        });
        for(auto p:properties){
            if(p[1]>=maxi)maxi=p[1];
            else cnt++;
        }
        return cnt;
    }
};