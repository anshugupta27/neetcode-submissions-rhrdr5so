class Solution {
public:
    bool isInterleaveRecursion (string s1, string s2, string s3, int index1, int index2, int index3, vector<vector<vector<int>>> &dp) {
        if (index1 >= s1.length() && index2 >= s2.length() && index3 == s3.length()) return true;
        if (dp[index1][index2][index3] != -1) return dp[index1][index2][index3];

        bool leftRecur = false, rightRecur = false;
        if (index1 < s1.length() && s3[index3] == s1[index1] ) {
            leftRecur = isInterleaveRecursion (s1, s2, s3, index1+1, index2, index3+1, dp);
        }
        if (index2 < s2.length() && s3[index3] == s2[index2]) {
            rightRecur = isInterleaveRecursion (s1, s2, s3, index1, index2+1, index3+1, dp);
        }
        return dp[index1][index2][index3] = leftRecur || rightRecur;
    }
    bool isInterleave(string s1, string s2, string s3) {
vector<vector<vector<int>>> dp(  // ✅ FIX 2
            s1.length() + 1,
            vector<vector<int>>(s2.length() + 1, vector<int>(s3.length() + 1, -1))
        );        
        return isInterleaveRecursion (s1, s2, s3, 0, 0, 0, dp);
    }
};
