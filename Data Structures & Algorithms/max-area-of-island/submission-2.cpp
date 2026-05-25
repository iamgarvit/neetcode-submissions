class Solution {
public:
    int n, m;
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int& area) {
        area++;
        for (auto [x1, y1] : dirs) {
            int x = i + x1;
            int y = j + y1;

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !visited[x][y]) {
                visited[x][y] = 1;
                dfs(grid, visited, x, y, area);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = 1;
                    int area = 0;

                    dfs(grid, visited, i, j, area);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};