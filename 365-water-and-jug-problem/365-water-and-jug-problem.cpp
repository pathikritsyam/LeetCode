class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(jug1Capacity+jug2Capacity<targetCapacity)return false;
        if(targetCapacity==0)return true;
        if(targetCapacity%gcd(jug1Capacity,jug2Capacity)==0)return true;
        return false;
    }
};