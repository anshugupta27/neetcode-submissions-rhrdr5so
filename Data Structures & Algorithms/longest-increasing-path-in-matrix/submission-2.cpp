class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool isValid (vector<vector<int>> matrix, int oldRow, int oldCol, int newRow, int newCol) {
        int rowSize = matrix.size(), colSize = matrix[0].size();
        if (newRow < rowSize && newRow >= 0 && newCol < colSize && newCol >= 0 && matrix[newRow][newCol] > matrix[oldRow][oldCol]) return true;
        return false;
    }

    int longestIncreasingPathRecursive (vector<vector<int>> matrix, int row, int col) {
        int maxVal = 1;
        for (int i = 0 ; i < 4 ; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (isValid(matrix, row, col, newRow, newCol)) {
               // matrix[row][col] = -1;
                maxVal = max (maxVal, 1 + longestIncreasingPathRecursive (matrix, newRow, newCol));
            }
        }
        return maxVal;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxLen = 0;
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
               maxLen = max (maxLen, longestIncreasingPathRecursive (matrix, i, j));
            }
        }
        return maxLen;
    }
};
