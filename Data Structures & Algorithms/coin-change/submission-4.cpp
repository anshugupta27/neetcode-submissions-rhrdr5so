class Solution {
public:
    int coinChangeRecursive(vector<int>& coins, int amount, int index, vector<vector<int>> &dp) {
        if (amount != 0 && index >= coins.size()) return INT_MAX;
        if (amount == 0) return 0;
        if (dp[amount][index] != -1) return dp[amount][index];
        if (amount < coins[index]) return dp[amount][index] = coinChangeRecursive(coins, amount, index+1, dp);
        else {
            int pick = coinChangeRecursive(coins, amount-coins[index], index, dp);
            int skip = coinChangeRecursive(coins, amount, index+1, dp);
            if (pick != INT_MAX) pick = 1 + pick;
            return dp[amount][index] = min(skip, pick);
        }

    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        vector<vector<int>> dp(amount+10, vector<int>(coins.size(), -1));
        int ans = coinChangeRecursive(coins, amount, 0, dp);
        if (ans == INT_MAX || ans == INT_MIN) return -1;
        return ans;
        
    }
};
