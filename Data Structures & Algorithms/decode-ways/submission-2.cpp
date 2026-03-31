class Solution {
public:
    bool isValid(string s, int start, int end) {
        if (start > end || s[start] == '0' || end-start+1 > 2) return false;
        string temp = s.substr(start, end-start+1);
        if (stoi(temp) > 26) return false;
        return true;

    }
    int numDecodingsUtil(string s, int start, vector<string> v, vector<int> &dp) {
        if (start == s.length() ) {
            return 1;
        }
        if (dp[start] != -1) return dp[start];
        int totalWays = 0;

        for (int end = start ; end < s.length() ; end++) {
            if (end-start+1 <= 2 && isValid(s, start, end) ) {
                v.push_back(s.substr(start, end-start+1));
                totalWays += numDecodingsUtil (s, end+1, v, dp);
                v.pop_back();
            }
        }
        return dp[start] = totalWays;
    }
    int numDecodings(string s) {
        vector<string> v;
        vector<int>dp(s.length(), -1);
        return numDecodingsUtil(s, 0, v, dp);
    }
};
