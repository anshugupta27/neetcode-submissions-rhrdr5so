class Solution {
public:
    int  findTargetSumWaysRecursive (vector<int>& nums, int target, int index, int currentValue) {
        if (index == nums.size() && target == currentValue) return 1;
        if (index == nums.size()) return 0;
        // sum and subtract
        return findTargetSumWaysRecursive (nums, target, index+1, currentValue+nums[index]) + findTargetSumWaysRecursive (nums, target, index+1, currentValue-nums[index]); 

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return findTargetSumWaysRecursive (nums, target, 0, 0);
    }
};
