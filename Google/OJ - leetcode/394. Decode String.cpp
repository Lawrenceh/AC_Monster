/* stack */
class Solution {
public:
    string decodeString(string s) {
        // nums: each level repeated times, num: current level parsed number
        // sts: each level "prefix" strings, res: all "prefix" string so far
        stack<int> nums; int num = 0;
        stack<string> sts; string res = "";
        for (auto c: s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (isalpha(c)) {
                res += c;
            } else if (c == '[') {
                sts.push(res); res = "";
                nums.push(num); num = 0;
            } else if (c == ']') {
                string t = "";
                for (int i = 0; i < nums.top(); i ++) {
                    t += res;
                }
                res = sts.top() + t;
                nums.pop();
                sts.pop();
            }
        }
        return res;
    }
};

/* recursive solution */
/* Leetcode discuss solution */
class Solution {
public:
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};

