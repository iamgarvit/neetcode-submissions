class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n != m) return false;

        unordered_map<char, int> s_hash, t_hash;

        for (int i = 0; i < n; i++) {
            s_hash[s[i]]++;
        }

        for (int i = 0; i < m; i++) {
            t_hash[t[i]]++;
        }

        for (auto& a : s_hash) {
            char c = a.first;
            int cnt = a.second;

            if (t_hash.find(c) != t_hash.end()) {
                if (t_hash[c] == cnt) {
                    continue;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};
