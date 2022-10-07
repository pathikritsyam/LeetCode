class MyCalendarTwo {
public:
    map<int,int>sweep;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int cur=0;
        sweep[start]++;
        sweep[end]--;
        for(auto &[_,val]:sweep){
            cur+=val;
            if(cur>2){
                sweep[start]--;
                sweep[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */