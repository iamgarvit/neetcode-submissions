class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        unordered_set<int> hashP;
        unordered_set<int> hashA;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> visitedP(n, vector<int>(m, 0));
        vector<vector<int>> visitedA(n, vector<int>(m, 0));

        stack<pair<int, int>> stP, stA;

        int x, y, x2, y2;

        for (int i = 0; i < n; i++) stP.push({i, 0});
        for (int j = 0; j < m; j++) stP.push({0, j});

        while (!stP.empty()) {
            x = stP.top().first;
            y = stP.top().second;
            stP.pop();

            if (visitedP[x][y]) continue;

            visitedP[x][y] = 1;
            hashP.insert(x * m + y);

            for (auto [dx, dy] : dirs) {
                x2 = x + dx;
                y2 = y + dy;

                if (x2 >= 0 && x2 < n &&
                    y2 >= 0 && y2 < m &&
                    !visitedP[x2][y2] &&
                    heights[x2][y2] >= heights[x][y]) {

                    stP.push({x2, y2});
                }
            }
        }

        for (int i = 0; i < n; i++) stA.push({i, m - 1});
        for (int j = 0; j < m; j++) stA.push({n - 1, j});

        while (!stA.empty()) {
            x = stA.top().first;
            y = stA.top().second;
            stA.pop();

            if (visitedA[x][y]) continue;

            visitedA[x][y] = 1;
            hashA.insert(x * m + y);

            for (auto [dx, dy] : dirs) {
                x2 = x + dx;
                y2 = y + dy;

                if (x2 >= 0 && x2 < n &&
                    y2 >= 0 && y2 < m &&
                    !visitedA[x2][y2] &&
                    heights[x2][y2] >= heights[x][y]) {

                    stA.push({x2, y2});
                }
            }
        }

        vector<vector<int>> ans;

        for (auto p : hashP) {
            if (hashA.find(p) != hashA.end()) {
                ans.push_back({p / m, p % m});
            }
        }

        return ans;
    }
};