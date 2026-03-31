class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool isValid(vector<vector<char>>& board, string word, int row, int col, int index) {
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && word[index] == board[row][col]) return true;
        return false;
    }

    bool existRecursion(vector<vector<char>>& board, string word, int row, int col, int index) {
        if (index >= word.length()) return true;

        if (!isValid(board, word, row, col, index)) return false;

        char temp = board[row][col] ;
        board[row][col] = '#';

        for (int i = 0 ; i < 4 ; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
          
        if(existRecursion(board, word, newRow, newCol, index+1)) return true;
            
        }
        board[row][col] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (existRecursion(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
