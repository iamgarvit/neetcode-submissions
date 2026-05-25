class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans = 0;
        stack<pair<int, int>> s;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = 1;
                    int tempCnt = 0;
                    s.push({i, j});

                    while (!s.empty()) {
                        int i = s.top().first;
                        int j = s.top().second;
                        tempCnt++;
                        s.pop();

                        for (auto [x1, y1] : dirs) {
                            int x = i + x1;
                            int y = j + y1;
                            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !visited[x][y]) {
                                visited[x][y] = 1;
                                s.push({x, y});
                            }
                        }

                    }
                    ans = max(ans, tempCnt);
                }
            }
        }
        return ans;
    }
};
