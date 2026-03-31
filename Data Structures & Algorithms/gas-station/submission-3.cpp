class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // loop through and find the max x-y and the index giving this may be the starting point
        // x = gas[i] , y = cost[i]
       int extra = 0, deficient = 0, potentialStartIndex = 0;
       for (int i = 0 ; i < gas.size() ; i++) {
        extra += gas[i];
        // if i cant survive with this gas till next station
        if (extra < cost[i]) {
            deficient += cost[i] - extra;
            extra = 0;
            potentialStartIndex = i+1;
        } else {  // if i can survive with this gas till next station
            extra -= cost[i];
        }
       }
        if (extra-deficient >= 0) return potentialStartIndex;
        return -1;
    
    }
};
