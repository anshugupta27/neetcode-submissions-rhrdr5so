class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    bool isValid (int prevRow, int prevCol, int newRow, int newCol, vector<vector<int>>& heights, vector<vector<int>> &visited ) {
        int totalRow = heights.size(), totalCol = heights[0].size();
        if (newRow >= 0 && newRow < totalRow && newCol >= 0 && newCol < totalCol && heights[newRow][newCol] >= heights[prevRow][prevCol] && visited[newRow][newCol] != 1) return true;
        return false;
    }
    void dfs (int row, int col, vector<vector<int>> &visited, vector<vector<int>>& heights) {
        for (int i = 0 ; i < 4 ; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if(isValid(row, col, newRow, newCol, heights, visited)) {
                visited[newRow][newCol] = 1;
                dfs(newRow, newCol, visited, heights);
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> pacificVisited(row,vector<int>(col,0)), atlanticVisited(row,vector<int>(col,0));
        vector<vector<int>> finalAns;
        for (int i = 0 ; i < col ; i++) {
            //top-0th row
            pacificVisited[0][i] = 1;
            dfs(0,i, pacificVisited, heights);
        }
        for (int i = 0 ; i < row ; i++) {
            // left side 0th col
            pacificVisited[i][0] = 1;
            dfs(i,0, pacificVisited, heights);
        }
        for (int i = 0 ; i < row ; i++) {
            // last col
            atlanticVisited[i][col-1] = 1;
            dfs(i,col-1, atlanticVisited, heights);
        }
        for (int i = 0 ; i < col ; i++) {
            // last row
            atlanticVisited[row-1][i] = 1;
            dfs(row-1,i, atlanticVisited, heights);
        }
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (pacificVisited[i][j] == 1 && atlanticVisited[i][j] == 1) finalAns.push_back({i,j});
            }
        }
        return finalAns;
    }
};
