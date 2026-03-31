class Solution {
public:
    bool verticalScan(vector<vector<char>>& board, int r, int c) {
        int row = board.size();
        for (int i = 0 ; i < row ; i++) {
            if (i != r && board[i][c] == board[r][c]) return false;
        }
        return true;
    }
    bool horizontalScan(vector<vector<char>>& board, int r, int c) {
        int col = board[0].size();
        for (int i = 0 ; i < col ; i++) {
            if (i != c && board[r][i] == board[r][c]) return false;
        }
        return true;
    }
     bool boxScan(vector<vector<char>>& board, int r, int c) {
        int col = board[0].size();
        int startRow = r / 3 * 3;
        int startCol = c / 3 * 3 ; 
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                if (r != startRow + i && c != startCol + j && board[r][c] == board[startRow + i ][startCol + j]) return false;
            }
        }
        return true;
    }
    // 2/3 2/3
    // 2 5 -> 0, 3
    // 1 4 -> 0 3
    // 0, 3 -> 0, 3
    // 0, 4
    // 0, 5
    // 1, 3
    // 1, 4
    // 1, 5
    // 2, 3
    // 2, 4
    // 2, 5 -> 2/3 * 3 

    bool isValidSudoku(vector<vector<char>>& board) {
        // for each cell check its corresponding entire and and then entire column if there is any same character 
        // then in 3*3 
        int row = board.size(), col = board[0].size();
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (board[i][j] != '.' && !verticalScan(board, i, j)) {
                    cout << "1, " << i << ", " << j;
                    return false;
                }
                if (board[i][j] != '.' && !horizontalScan(board, i, j)) {
                     cout << "2";
                    return false;
                }
                if (board[i][j] != '.' && !boxScan(board, i, j)) {
                     cout << "3";
                    return false;
                }
            }
        }
        return true;
    }
};
