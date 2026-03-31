class Solution {
public:
    int dp[1000000][2];
    int robUtil (vector<int>& nums, int n, bool take) {
        if (n >= nums.size()) return 0;
        if (dp[n][take] != -1) return dp[n][take];
        if (take) return dp[n][take] = max(robUtil(nums, n+1, take), nums[n] + robUtil(nums, n+1, !take));
        return dp[n][take] = robUtil (nums, n+1, !take);

    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return max(robUtil (nums, 0, true), robUtil (nums, 0, false));

    }
};
