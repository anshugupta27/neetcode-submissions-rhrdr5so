class Solution {
public:
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
    bool isValid(int row, int col, vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        if (row >= 0 && row < r && col >= 0 && col < c && grid[row][col] == 1) return true;
        return false;
    }
    int calculateTimeToRott(vector<vector<int>>& grid, queue<pair<int,int>> &rottenQ) {
        int minutes = -1;
        while (!rottenQ.empty()) {
            int size = rottenQ.size();
            minutes++;
            while (size--) {
                auto front = rottenQ.front();
                int row = front.first;
                int col = front.second;
                rottenQ.pop();
                for (int i = 0 ; i < 4 ; i++) {
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];
                    if (isValid(newRow, newCol, grid)) {
                        grid[newRow][newCol] = 2;
                        rottenQ.push({newRow, newCol});
                    }
                }

            }
        }
        return minutes;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>rottenQ;
        int fresh = 0;
        for (int i = 0 ; i < grid.size() ; i++) {
            for (int j = 0 ; j < grid[0].size() ; j++) {
                if (grid[i][j] == 2) {
                    rottenQ.push({i,j});
                } else if (grid[i][j] == 1) fresh++;
            }
        }
        if (rottenQ.empty() && fresh != 0) return -1;
        if (rottenQ.empty() && fresh == 0) return 0;
        int minutes = calculateTimeToRott(grid, rottenQ);
        for (int i = 0 ; i < grid.size() ; i++) {
            for (int j = 0 ; j < grid[0].size() ; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minutes;
        
       
    }
};
