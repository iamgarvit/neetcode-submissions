class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, vector<int>& curr, int currSum, int target, int ind) {
        if (ind >= candidates.size()) {
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) {
                continue;
            }
            int num = candidates[i];
            if (currSum + num == target) {
                curr.push_back(num);
                ans.push_back(curr);
                curr.pop_back();
            }
            else if (currSum  + num < target) {
                curr.push_back(num);
                currSum += num;
                solve(candidates, curr, currSum, target, i + 1);
                curr.pop_back();
                currSum -= num;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        solve(candidates, curr, 0, target, 0);
        return ans;
    }
};
