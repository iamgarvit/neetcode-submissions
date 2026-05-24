class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& curr, int ind) {
        if (ind == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[ind]);
        solve(nums, curr, ind + 1);

        curr.pop_back();
        solve(nums, curr, ind + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(nums, curr, 0);
        return ans;
    }
};
