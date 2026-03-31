class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) return false;
            start++, end--;
        }
        
        return true;

    }
    int longestPalindromeRecursive (string s, int start, int end, vector<vector<int>> &dp) {
        if (start > end) return 0;
        
        if (dp[start][end] != -1) return dp[start][end];
        int count = 0;
        if (isPalindrome(s, start, end)) count = 1;

        count += longestPalindromeRecursive (s, start+1, end, dp);
        count += longestPalindromeRecursive(s, start, end-1, dp);
        count -= longestPalindromeRecursive(s, start+1, end-1, dp);
        return dp[start][end] = count;
    }
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int ans = longestPalindromeRecursive (s, 0, n-1, dp);
         for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                cout << dp[i][j] << ", ";
            }
            cout << "\n";
         }
         return ans;

        
    }
};