class Solution {
public:
    int longestCommonSubsequenceRecursive(int ptr1, int ptr2, string text1, string text2, vector<vector<int>> &dp) {
        if (ptr1 == text1.length() || ptr2 == text2.length()) {
            return 0;
        }
        if (dp[ptr1][ptr2] != -1) return dp[ptr1][ptr2];

        if (text1[ptr1] == text2[ptr2]) {
            return dp[ptr1][ptr2] = 1 + longestCommonSubsequenceRecursive(ptr1+1, ptr2+1, text1, text2, dp);
        } 
        return dp[ptr1][ptr2] = max(longestCommonSubsequenceRecursive(ptr1+1, ptr2, text1, text2, dp),
            longestCommonSubsequenceRecursive(ptr1, ptr2+1, text1, text2, dp));

    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return longestCommonSubsequenceRecursive(0, 0, text1, text2, dp);
    }
};
