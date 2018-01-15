class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> stk;
        int x, y;
        for (auto s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                y = stk.top();
                stk.pop();
                x = stk.top();
                stk.pop();
                if (s == "+") stk.push(x + y);
                else if (s == "-") stk.push(x - y);
                else if (s == "*") stk.push(x * y);
                else stk.push(x / y);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};
