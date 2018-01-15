/* NOTE: for complete calculator implementation, think of converting this expression to RPN, then evaluate */

/* no priority on operators, stack is used to store previous result */

class Solution {
public:
    int calculate(string s) {
        /* res: previous calcuated result 
         * curr: current number
         * sign: previous operator sign, starting with +1
         * stk: used to store previous results
         */
        int res = 0;
        int curr = 0;
        stack<int> stk;
        int sign = 1; // 1: +, -1: -,
        for (auto c: s) {
            if (c == ' ') continue;
            if (isdigit(c)) {
                curr = curr * 10 + c - '0';
            } else if (c == '+') {
                res += sign * curr;
                sign = 1;
                curr = 0;
            } else if (c == '-') {
                res += sign * curr;
                sign = -1;
                curr = 0;
            } else if (c == '(') {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1; // no need for current number reset (gotta be a valid expression)
            } else if (c == ')') {
                // first parse latest number and add it to res (in this brackets)
                res += sign * curr;
                curr = res;
                sign = stk.top();
                stk.pop();
                res = stk.top();
                stk.pop();
            }
        }
        // handle last number operation
        res += sign * curr;
        return res;
    }
};
