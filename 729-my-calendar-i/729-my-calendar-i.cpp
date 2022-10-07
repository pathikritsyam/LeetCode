class MyCalendar {
public:
    map<int,int>sweep;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int cur=0;
        sweep[start]++;
        sweep[end]--;
        for(auto [_,val]:sweep){
            cur+=val;
            if(cur>1){
                sweep[start]--;
                sweep[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */