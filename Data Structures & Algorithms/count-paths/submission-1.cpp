class Solution {
public:
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
    bool isValid(int row, int col, int m, int n) {
        if (row < 0 || row >= m || col < 0 || col >= n) return false;
        return true;

    }
    int uniquePathsRecursive(int row, int col, int m, int n, vector<vector<int>> &dp) {
        if (row == m-1 && col == n-1) return 1;
        if (row > m || col > n) return 0;
        int sum = 0;
        if (dp[row][col] != -1) return dp[row][col];

        for (int i = 0 ; i < 2 ; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (isValid(newRow, newCol, m, n)) {
                sum += uniquePathsRecursive(newRow, newCol, m, n, dp);
            }
        }
        return dp[row][col] = sum;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePathsRecursive(0, 0, m, n, dp);
    }
};