class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), columns = matrix[0].size();

        int row_l = 0, row_h = rows - 1, col_l = 0, col_h = columns - 1;
        int row_mid = 0, col_mid = 0;
        while (row_l <= row_h) {
            row_mid = row_l + (row_h - row_l) / 2;
            if (matrix[row_mid][col_l] <= target && target <= matrix[row_mid][col_h]) {
                while (col_l <= col_h) {
                    col_mid = col_l + (col_h - col_l) / 2;
                    if (target == matrix[row_mid][col_mid]) {
                        return true;
                    }
                    else if (target > matrix[row_mid][col_mid]) {
                        col_l = col_mid + 1;
                    }
                    else {
                        col_h = col_mid - 1;
                    }
                }
            }
            else if (matrix[row_mid][col_h] > target) {
                row_h = row_mid - 1;
            }
            else {
                row_l = row_mid + 1;
            }
        }
        return false;
    }
};
