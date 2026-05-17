class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1;
        int n = s.length();
        if (n == 0 || n == 1)   return n;
        
        unordered_set<char> seen;

        int l = 0, r = 1;
        seen.insert(s[0]);
        while (l < n && r < n && l <= r) {
            if (seen.find(s[r]) == seen.end()) {
                ans = max(ans, r - l + 1);
                seen.insert(s[r]);
                r++;
            }
            else {
                seen.erase(s[l]);
                l++;
            }
        }

        return ans;
    }
};
