class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for (string c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int num1 = stoi(st.top());
                st.pop();
                int num2 = stoi(st.top());
                st.pop();
                if (c == "+") {
                    st.push(to_string(num2 + num1));
                }
                else if (c == "-") {
                    st.push(to_string(num2 - num1));
                }
                else if (c == "*") {
                    st.push(to_string(num2 * num1));
                }
                else {
                    st.push(to_string(num2 / num1));
                }
            }
            else {
                st.push(c);
            }
        }
        return stoi(st.top());
    }
};
