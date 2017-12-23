class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> nums) {
        sum.push_back(0);
        for (auto n: nums) {
            sum.push_back(sum.back() + n);
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
