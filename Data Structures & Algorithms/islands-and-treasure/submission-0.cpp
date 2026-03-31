class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    bool isValid(int row, int col, vector<vector<int>>& grid){
        if (row < grid.size() && row >= 0 && col < grid[0].size() && col >= 0 && grid[row][col] == 2147483647) return true;
        return false;

    }
    void bfs( queue<pair<pair<int,int>,int>> &q, vector<vector<int>>& grid) {

        while (q.size()) {
            int size = q.size();
            while (size--) {
                auto front = q.front();
                int row = front.first.first;
                int col = front.first.second;
                int distance = front.second;
                q.pop();
                for (int i = 0 ; i < 4 ; i++) {
                  int newRow = row + dx[i], newCol = col + dy[i];
                  if (isValid(newRow, newCol, grid)) {
                  grid[newRow][newCol] = min(distance+1, grid[newRow][newCol])  ;
                  q.push({{newRow, newCol}, distance+1});
                }
        }


            }
        }

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int row = grid.size(), col = grid[0].size();
       for (int i = 0 ; i < row ; i++) {
        for (int j = 0 ; j < col ; j++) {
           if (grid[i][j] == 0) q.push({{i,j}, 0});
        }
       }
       //[(2,0), 0, (3,0),0] 
       bfs(q, grid);


    }
};
