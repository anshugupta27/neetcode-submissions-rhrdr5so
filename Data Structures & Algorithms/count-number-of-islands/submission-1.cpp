class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    bool isValid(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int totalRow = grid.size(), totalCol = grid[0].size();
        if (row < 0 || row >= totalRow || col < 0 || col >= totalCol || visited[row][col] == 1 || grid[row][col] == '0') return false;
        return true;
    }

    void visitIslandDfs (vector<vector<char>>& grid, vector<vector<int>>& visited, int row, int col) {
        visited[row][col] = 1;
        for (int dir = 0 ; dir < 4 ; dir++) {
            int childRow = row + dx[dir];
            int childCol = col + dy[dir];
            if (isValid(childRow, childCol, grid, visited)) {
                visitIslandDfs (grid, visited, childRow, childCol);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), island = 0;
        vector<vector<int>> visited (row, vector<int>(col, -1));
        for (int row_itr = 0 ; row_itr < row ; row_itr++) {
            for (int col_itr = 0 ; col_itr < col ; col_itr++) {
                if (visited[row_itr][col_itr] == -1 && grid[row_itr][col_itr] == '1') {
                    island++;
                    visitIslandDfs (grid, visited, row_itr, col_itr);
                }
            }
        }
        return island;
    }
};