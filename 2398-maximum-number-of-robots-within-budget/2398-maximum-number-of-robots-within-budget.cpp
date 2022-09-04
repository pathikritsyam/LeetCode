class Solution {
public:
    int maximumRobots(vector<int>& time, vector<int>& cost, long long budget) {
        multiset<int>s;
        long long sum=0,i=0,n=cost.size();
        for(int j=0;j<n;j++){
            sum+=cost[j];
            s.insert(time[j]);
            if(*s.rbegin()+(j-i+1)*sum>budget){
                sum-=cost[i];
                s.erase(s.find(time[i++]));
            }
        }
        return n-i;
    }
};