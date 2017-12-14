/* sorting method */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (int i = 0; i < citations.size(); i ++) {
            if (citations[i] >= i + 1) {
                if ((i != citations.size() - 1 && citations[i + 1] <= i + 1) || i == citations.size() - 1) h = i + 1;
            }
        }
        return h;
    }
};

/* wiki's logic */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i ++) {
            if (citations[i] < i + 1) {
                return i;
            }
        }
        return citations.size(); // 0, 1 cases
    }
};

/* O(n) solution - counting sort idea */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        /* O(n) solution */
        int n = citations.size();
        int a[n + 1];
        memset(a, 0, sizeof(int) * (n + 1));
        for (auto c: citations) {
            if (c > n) {
                a[n] ++;
            } else {
                a[c] ++;
            }
        }
        int s = 0;
        for (int i = n; i >= 0; i --) {
            s += a[i];
            if (s >= i) return i;
        }
        return 0; // doesn't help but .. be safe
    }
};
