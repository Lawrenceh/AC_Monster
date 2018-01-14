class Solution {
public:
    unordered_set<int> visited;
    bool isHappy(int n) {
        if (n == 1) return true;
        if (visited.count(n)) return false;
        visited.insert(n);
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return isHappy(sum);
    }
};
