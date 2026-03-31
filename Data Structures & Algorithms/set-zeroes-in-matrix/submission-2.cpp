class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 0 1 1
        // 1 1 1
        // 1 1 1
        bool setRight = false, setBottom = false;
        int row = matrix.size(), col = matrix[0].size();
        if (matrix[0][0] == 0) {
            setRight = true;
            setBottom = true;
        }
        for (int i = 0 ; i < col ; i++) {
            if (matrix[0][i] == 0) setRight = true;
        }
        for (int i = 0 ; i < row ; i++) {
            if (matrix[i][0] == 0) setBottom = true;
        }

        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = row-1 ; i >= 0 ; i--) {
            for (int j = col-1 ; j >= 0 ; j--) {
                if (i != 0 && j != 0 && (matrix[0][j] == 0 || matrix[i][0] == 0)) matrix[i][j] = 0;
                if (i == 0 && setRight) matrix[i][j] = 0;
                if (j == 0 && setBottom) matrix[i][j] = 0;
            }
        }
    }
};
