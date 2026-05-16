class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash;
        hash[nums[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }

        return {};
    }
};
