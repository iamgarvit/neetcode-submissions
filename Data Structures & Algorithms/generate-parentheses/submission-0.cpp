class Solution {
public:
    vector<string> ans;

    void solve(string s, int n, int open, int close) {
        if (open < close)   return;
        if (open > n || close > n)  return;
        if (open == close && open == n) {
            ans.push_back(s);
            return;
        }

        string temp = s + "(";
        solve(temp, n, open + 1, close);
        string temp1 = s + ")";
        solve(temp1, n, open, close + 1);
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(s, n, 0, 0);
        return ans;
    }
};
