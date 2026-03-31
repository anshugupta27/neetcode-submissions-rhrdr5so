class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        uint32_t test = 0;
        for (int i = 0 ; i <= n ; i++) {
            test = test xor i;
        }
        for (int i = 0 ; i < n ; i++) {
            test = test xor nums[i];
        }
        return test;
    }
};
