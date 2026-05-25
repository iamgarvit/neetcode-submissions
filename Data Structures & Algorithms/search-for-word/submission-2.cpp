class Solution {
public:
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int ind, int n, int m, int i, int j) {
        if (ind == word.length())   return true;

        for (auto [x1, y1] : dirs) {
            int x = i + x1;
            int y = j + y1;

            if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == word[ind] && !visited[x][y]) {
                visited[x][y] = 1;
                bool val = dfs(board, visited, word, ind + 1, n, m, x, y);
                if (val)    return val;
                visited[x][y] = 0;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ind = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[ind]) {
                    visited[i][j] = 1;
                    bool ans = dfs(board, visited, word, ind + 1, n, m, i, j);
                    if (ans)    return ans;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};
