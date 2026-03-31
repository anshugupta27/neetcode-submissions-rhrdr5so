class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++, end--;
        }
        return true;

    }
    string longestPalindromeRecursive (string s, int start, int end, vector<vector<string>> &dp) {
        if (start > end) return "";
        if (dp[start][end] != "-1") return dp[start][end];
        if (isPalindrome(s, start, end)) return s.substr(start, end-start+1);
        string left = longestPalindromeRecursive (s, start+1, end, dp);
        string right = longestPalindromeRecursive(s, start, end-1, dp);
        return dp[start][end] = left.length() > right.length() ? left : right;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<string>> dp(n, vector<string>(n,"-1"));
        return longestPalindromeRecursive (s, 0, n-1, dp);
        
    }
};