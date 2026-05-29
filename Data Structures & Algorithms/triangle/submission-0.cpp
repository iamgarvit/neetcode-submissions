class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), arrS;
        for (int i = n - 2; i >= 0; i--) {
            arrS = triangle[i].size();
            for (int j = 0; j < arrS; j++) {
                triangle[i][j] += min(triangle[i + 1][j + 1], triangle[i + 1][j]);
            }
        }
        return triangle[0][0];
    }
};