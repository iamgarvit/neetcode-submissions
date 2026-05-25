class Solution {
public:
    vector<string> ans;

    void solve(string& s, int n, int open, int close) {
        if (open < close)   return;
        if (open > n || close > n)  return;
        if (open == close && open == n) {
            ans.push_back(s);
            return;
        }

        s.push_back('(');
        solve(s, n, open + 1, close);
        s.pop_back();
        s.push_back(')');
        solve(s, n, open, close + 1);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(s, n, 0, 0);
        return ans;
    }
};
