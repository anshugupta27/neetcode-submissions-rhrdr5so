class Solution {
public:
    void combinationSumRecursion(vector<int> &nums, int target, int index, vector<int>&tempAns, vector<vector<int>> &finalAns) {
        if (target == 0) {
             finalAns.push_back(tempAns);
             return;
        }
        if (target < 0 || index >= nums.size()) return;

        tempAns.push_back(nums[index]);
        combinationSumRecursion(nums, target-nums[index], index, tempAns, finalAns);
        tempAns.pop_back();
        combinationSumRecursion(nums, target, index+1, tempAns, finalAns);


    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> tempAns;
        vector<vector<int>> finalAns;
        combinationSumRecursion(nums, target, 0, tempAns, finalAns);
        return finalAns;
        
    }
};
