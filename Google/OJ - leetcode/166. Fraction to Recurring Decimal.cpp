class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long n = numerator, d = denominator;
        if (n == 0) return "0";
        string res;
        if (n < 0 ^ d < 0) res += '-';
        n = abs(n); d = abs(d);
        res += to_string(n / d);
        if (!(n % d)) return res;
        res += '.';
        long r = n % d;
        unordered_map<int, int> m; // mapping from remainder to its position
        while (r % d) {
            r %= d;
            if (m.count(r) > 0) { // if we encounter the same remainder we saw before, it means that this digit was seen before too
                res.insert(m[r], "(");
                res += ')';
                return res;
            } else {
                m[r] = res.size();
            }
            r *= 10;
            res += to_string(r / d);
        }
        return res;
    }
};
