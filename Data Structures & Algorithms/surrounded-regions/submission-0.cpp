class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool isValid(int row, int col, vector<vector<char>>& board) {
        int totalRow = board.size(), totalCol = board[0].size();
        if (row >= 0 && row < totalRow && col >= 0 && col < totalCol && board[row][col] == 'O') return true;
        return false;

    }
    void dfs(int row, int col, vector<vector<char>>& board) {
        board[row][col] = '2';
        for (int i = 0;i < 4 ; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (isValid(newRow, newCol, board)) {
                dfs(newRow, newCol, board);

            }
        }

    }
    void solve(vector<vector<char>>& board) {
        // apply dfs on all border elements if its a zero
        int row = board.size(), col = board[0].size();
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if ((i == 0 || i == row-1 || j == 0 || j == col-1 )&& board[i][j] == 'O') {
                    dfs(i, j, board);
                }
            }
        }
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (board[i][j] == '2') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

};
