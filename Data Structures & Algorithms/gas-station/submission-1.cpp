class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // loop through and find the max x-y and the index giving this may be the starting point
        // x = gas[i] , y = cost[i]
        // int potentialStartingPoint = -1, maxGasFilled = 0;
        // for (int i = 0 ; i < gas.size() ; i++) {
        //     if (maxGasFilled < gas[i]-cost[i]) {
        //     maxGasFilled = max (maxGasFilled, gas[i]-cost[i]);
        //     potentialStartingPoint = i;
        //     }
        // }
        for (int potentialStartingPoint = 0 ; potentialStartingPoint < gas.size() ; potentialStartingPoint++) {
        int gasLeftOver = 0;
        bool flag = true;
        for (int i = potentialStartingPoint ; i < gas.size() ; i++) {
            if (gas[i] + gasLeftOver < cost[i]) flag = false;
            gasLeftOver += gas[i] - cost[i];
        }
        for (int i = 0 ; i < potentialStartingPoint ; i++) {
            if (gas[i] + gasLeftOver < cost[i]) flag = false;
            gasLeftOver += gas[i] - cost[i];
        }       
        if (flag) return potentialStartingPoint;
    }
       
        return -1;
    }
};
