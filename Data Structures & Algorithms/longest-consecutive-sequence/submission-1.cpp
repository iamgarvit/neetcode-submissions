class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)   return n; 
        unordered_set<int> present;

        for (int num : nums) {
            present.insert(num);
        }

        int ans = 1;
        for (int a : present) {
            if (present.find(a - 1) != present.end()) {
                continue;
            }
            int cnt = 1;
            int current = a;
            while (true) {
                if (present.find(current + 1) != present.end()) {
                    current++;
                    cnt++;
                    ans = max(ans, cnt);
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};
