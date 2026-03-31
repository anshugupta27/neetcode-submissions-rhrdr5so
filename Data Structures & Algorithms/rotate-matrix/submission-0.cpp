class Solution {
public:
    void swap (int row, int col, vector<vector<int>>& matrix) {
        int temp = matrix[row][col];
        matrix[row][col] = matrix[col][row];
        matrix[col][row] = temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (i > j) {
                    swap(i,j,matrix);
                }
            }
        }
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col/2 ; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][col-j-1];
                matrix[i][col-j-1] = temp;
            }
        }
        
    }
};
