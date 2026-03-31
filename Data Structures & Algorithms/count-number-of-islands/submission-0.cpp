class Solution {
public:
    bool isValid(int row, int col, vector<vector<char>>& grid){
        if (row < grid.size() && row >= 0 && col < grid[0].size() && col >= 0 && grid[row][col] == '1') return true;
        return false;

    }
     void numIslandsBFS(int row, int col , vector<vector<char>>& grid) {
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        grid[row][col] = 2;
        for (int i = 0 ; i < 4 ; i++) {
            int newRow = row + dx[i], newCol = col + dy[i];
            if (isValid(newRow, newCol, grid)) {
                 numIslandsBFS(newRow, newCol, grid);
            }
        }

     }
    int numIslands(vector<vector<char>>& grid) {
        int island = 0, row = grid.size(), col = grid[0].size();
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (grid[i][j] == '1') {
                    numIslandsBFS(i, j, grid) ;
                    island++;
                }

            }
        }
        return island;
        
    }
};
