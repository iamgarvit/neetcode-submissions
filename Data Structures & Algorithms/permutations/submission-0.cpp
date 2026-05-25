class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& curr, vector<int>& seen) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!seen[i]) {
                curr.push_back(nums[i]);
                seen[i] = 1;
                solve(nums, curr, seen);
                curr.pop_back();
                seen[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<int> seen(nums.size(), 0);
        solve(nums, curr, seen);
        return ans;
    }
};
