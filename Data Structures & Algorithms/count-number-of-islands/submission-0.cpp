class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int n, int m, int i, int j) {
        for (auto [x1, y1] : dirs) {
            int x = i + x1;
            int y = j + y1;

            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] == '1') {
                visited[x][y] = 1;
                dfs(grid, visited, n, m, x, y);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    visited[i][j] = 1;
                    islands++;
                    dfs(grid, visited, n, m, i, j);
                }
            }
        }
        return islands;
    }
};
