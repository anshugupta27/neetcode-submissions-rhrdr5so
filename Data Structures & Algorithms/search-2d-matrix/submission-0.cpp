class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size()-1, maxRow = matrix.size();
        while (row < maxRow && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row = row + 1;
            else col = col-1;
        }
        return false;
    }
};
