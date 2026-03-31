class Solution {
public:
    bool isFound(string s, vector<string>& wordDict) {
        auto it = std::find(wordDict.begin(), wordDict.end(), s);
        if (it != wordDict.end()) return true;
        return false;
    }
    int wordBreakRecursive(string s, vector<string>& wordDict, int start, bool &finalAns, vector<int> &dp) {
        if (start >= s.length()) {
            finalAns = true;
            cout << "stop\n";
            return true;
        }
        if (dp[start] != -1) return dp[start];
        bool ans = false;
        for (int end = start ; end < s.length() ; end++) {
            string temp = s.substr(start, end-start+1);
            if (isFound(temp, wordDict)) {
                cout << temp << ", ";
                ans = wordBreakRecursive(s, wordDict, end+1, finalAns, dp);
            }
        }
        if (ans == true) dp[start] = 1;
        else dp[start] = 0;
        return dp[start];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        bool finalAns = false;
        vector<int>dp(s.length()+1, -1);
        wordBreakRecursive(s, wordDict, 0, finalAns, dp);
        return finalAns;
    }
};
