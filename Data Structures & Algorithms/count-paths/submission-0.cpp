class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        int up, left;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                
                up = (j - 1 >= 0 && j - 1 < n) ? dp[i][j - 1] : 0;
                left = (i - 1 >= 0 && i - 1 < m) ? dp[i - 1][j] : 0;
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};