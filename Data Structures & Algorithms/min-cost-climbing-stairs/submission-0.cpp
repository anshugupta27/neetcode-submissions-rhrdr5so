class Solution {
public:
    int minCostClimbingStairsUtil(vector<int>& cost, int n) {
         if (n >= cost.size()) return 0;
         return cost[n] + min (minCostClimbingStairsUtil (cost, n+1), minCostClimbingStairsUtil (cost, n+2));

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int minCost1 = 0, minCost2 = 0;
        return min(minCostClimbingStairsUtil(cost, 0),minCostClimbingStairsUtil(cost, 1));
        
    }
};
