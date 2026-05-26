class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        if (cnt == 0)   return 0;
        int time = 0;

        while (!q.empty()) {
            int curr_cnt = q.size();
            bool change = false;
            int x1, y1, x, y;

            for (int i = 0; i < curr_cnt; i++) {
                x1 = q.front().first;
                y1 = q.front().second;
                q.pop();
                
                for (auto [x2, y2] : dirs) {
                    x = x1 + x2;
                    y = y1 + y2;
                    
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                        change = true;
                        cnt--;
                    }
                }
            }
            if (change) time++;
        }
        
        return cnt == 0 ? time : -1;
    }
};
