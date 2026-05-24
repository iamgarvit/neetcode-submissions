class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& curr, int currSum, int target, int ind) {
        if (ind == nums.size()) {
            return;
        }

        for (int i = ind; i < nums.size(); i++) {
            int num = nums[i];
            if (currSum + num == target) {
                curr.push_back(num);
                ans.push_back(curr);
                curr.pop_back();
            }
            else if (currSum + num < target) {
                curr.push_back(num);
                currSum += num;
                solve(nums, curr, currSum, target, i);
                curr.pop_back();
                currSum -= num;
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        solve(nums, curr, 0, target, 0);
        return ans;
    }
};
