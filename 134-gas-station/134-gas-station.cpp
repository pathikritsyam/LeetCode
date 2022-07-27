class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),maxlen=0,tank=0;
        for(int i=0;i<n*2;i++){
            tank+=gas[i%n]-cost[i%n];
            if(tank>=0)maxlen++;
            else maxlen=0;
            tank=max(tank,0);
        }
        if(maxlen>=n)return n*2-maxlen;
        return -1;
    }
};