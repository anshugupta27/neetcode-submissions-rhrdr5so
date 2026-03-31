class Solution {
public:
    int dp[1000000][2][2];
    int robUtil (vector<int>& nums, int n, bool isFirstTake, bool take) {
        if (n >= nums.size()) return 0;
        if (dp[n][take][isFirstTake] != -1) return dp[n][take][isFirstTake];

        if ( n == nums.size()-1 && isFirstTake) return dp[n][take][isFirstTake] = 0;
        if ( n == nums.size()-1 && !isFirstTake)  dp[n][take][isFirstTake] = nums[n];
        if (take) return dp[n][take][isFirstTake] = max(robUtil(nums, n+1, isFirstTake, take), nums[n] + robUtil(nums, n+1, isFirstTake, !take));
        return dp[n][take][isFirstTake] = robUtil (nums, n+1, isFirstTake, !take);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        if (n == 0 ) return 0;
        if (n == 1) return nums[0];
        return max(robUtil (nums, 0, true, true), robUtil (nums, 0, false, false));

    }
};
