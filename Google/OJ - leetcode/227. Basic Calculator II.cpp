/* NOTE: for complete calculator implementation, think of converting this expression to RPN, then evaluate */

/* Use a stack to store values calculated. When * and / are encountered, we operate on curr and stk.top() */

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int curr = 0;
        stack<int> stk;
        char sign = '+';
        for (auto c: s) {
            if (c == ' ') continue;
            if (isdigit(c)) {
                curr = curr * 10 + c - '0';
            } else {
                if (sign == '+') stk.push(curr);
                else if (sign == '-') stk.push(-curr);
                else if (sign == '*' || sign == '/') {
                    int val = stk.top();
                    stk.pop();
                    stk.push((sign == '*') ? val * curr : val / curr);
                }
                sign = c;
                curr = 0;
            }
        }
        // hanlde last number
        if (sign == '+') stk.push(curr);
        else if (sign == '-') stk.push(-curr);
        else if (sign == '*' || sign == '/') {
            int val = stk.top();
            stk.pop();
            stk.push((sign == '*') ? val * curr : val / curr);
        }
        // sum up all numbers in stack
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
