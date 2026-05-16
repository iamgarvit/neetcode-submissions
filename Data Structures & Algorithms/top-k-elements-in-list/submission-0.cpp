class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;

        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }

        vector<vector<int>> freq(n + 1);

        for (auto& a : hash) {
            int num = a.first;
            int cnt = a.second;
            freq[cnt].push_back(num);
        }

        vector<int> ans;
        for (int i = n; i >= 1 && ans.size() < k; i--) {
            for (int x : freq[i]) {
                ans.push_back(x);
                if (ans.size() == k) {
                    break;
                }
            }
        }

        return ans;
    }
};
