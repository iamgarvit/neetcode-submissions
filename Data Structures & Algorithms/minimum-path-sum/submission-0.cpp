class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int up, left;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)   continue;
                left = (i - 1 >= 0 && i - 1 < n) ? grid[i - 1][j] : INT_MAX;
                up = (j - 1 >= 0 && j - 1 < m) ? grid[i][j - 1] : INT_MAX;
                grid[i][j] += min(left, up);
            }
        }
        return grid[n - 1][m - 1];
    }
};