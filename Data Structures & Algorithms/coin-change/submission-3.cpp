class Solution {
public:
    int coinChangeRecursive(vector<int>& coins, int amount, int index) {
        if (amount != 0 && index >= coins.size()) return INT_MAX;
        if (amount == 0) return 0;
        if (amount < coins[index]) return coinChangeRecursive(coins, amount, index+1);
        else {
            int pick = coinChangeRecursive(coins, amount-coins[index], index);
            int skip = coinChangeRecursive(coins, amount, index+1);
            if (pick != INT_MAX) pick = 1 + pick;
            return min(skip, pick);
        }

    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        int ans = coinChangeRecursive(coins, amount, 0);
        if (ans == INT_MAX || ans == INT_MIN) return -1;
        return ans;
        
    }
};
