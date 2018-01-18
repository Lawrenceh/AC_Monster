Example:

Problem:
Given an array of length n, find consecutive subarray with max sum, whose length is <= m.

Analysis:
Without constraint m, this could be solved in O(n) time and O(1) space.
With the constraint, dp -> f[i] = sum[i] - min{sum[k]}, i - m <= k <= i

Naive implementation is O(n*n).
ST implementation is O(nlogn).

There is "monotone queue dp optimization" implementation, O(n) time:
/* we analyze on the element we are about to push into the queue, here i.e. checking its f[i] value */
/* Complexity: each number would be queued and dequeued once, therefore it's linear! */
#include <iostream>
#include <list>
#include <cstdio>
using namespace std;

int n, m;
long long s[300005];

list<int> queue; // could also use deque

int main() {
    cin >> n >> m;
    s[0] = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    long long maxx = 0;
    for (int i = 1; i <= n; i ++) {
        // if queue front > current s[i], front value definitely won't appear in the smallest closest m numbers
        while (!queue.empty() and s[queue.front()] > s[i]) queue.pop_front(); 
        queue.push_front(i);
        while (i - queue.back() > m) queue.pop_back(); // the smallest one expires (not close enough)
        maxx = max(maxx, s[i] - s[queue.back()]);
    }
    cout << maxx << endl;
    return 0;
}


Another example: See "239. Sliding Window Maximum.cpp" in "OJ - leetcode" folder.
