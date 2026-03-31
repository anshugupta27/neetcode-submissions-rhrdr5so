class Solution {
public:
    int changeRecursion (int amount, vector<int>& coins, int index, int currentValue, vector<vector<int>> &dp) {
         if (amount == currentValue) return 1;
         if (currentValue > amount || index >= coins.size()) return 0;
         if (dp[index][currentValue] != -1) return dp[index][currentValue];
         return dp[index][currentValue] = changeRecursion (amount, coins, index, currentValue+coins[index], dp) + changeRecursion (amount, coins, index+1, currentValue, dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount, -1));
        return changeRecursion (amount, coins, 0, 0, dp);
    }
};
