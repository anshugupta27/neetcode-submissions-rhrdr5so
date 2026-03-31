class Solution {
public:
    void combinationSum2Recursion(vector<int> &nums, int target, int index, vector<int>&tempAns, vector<vector<int>> &finalAns) {
        if (target == 0) {
             finalAns.push_back(tempAns);
             return;
        }
        if (target < 0 || index >= nums.size()) return;

        tempAns.push_back(nums[index]);
        combinationSum2Recursion(nums, target-nums[index], index+1, tempAns, finalAns);
        tempAns.pop_back();
        int j = index+1;
        while (j < nums.size() && nums[index] == nums[j])j++;
        combinationSum2Recursion(nums, target, j, tempAns, finalAns);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tempAns;
        vector<vector<int>> finalAns;
        sort(candidates.begin(), candidates.end());
        combinationSum2Recursion(candidates, target, 0, tempAns, finalAns);
        return finalAns;
    }
};
