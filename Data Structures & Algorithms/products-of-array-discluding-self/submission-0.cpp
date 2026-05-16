class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n, 1), next(n, 1);

        for (int i = 1; i < n; i++) {
            prev[i] = nums[i - 1] * prev[i - 1]; 
        } 

        for (int i = n - 2; i >= 0; i--) {
            next[i] = nums[i + 1] * next[i + 1];
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(prev[i] * next[i]);
        }

        return ans;
    }
};
