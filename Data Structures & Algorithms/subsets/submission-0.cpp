class Solution {
public:
    void  subsetsRecursion(vector<int>& nums, int index, vector<int> &finalAns, vector<vector<int>> &ans) {
        if (index >= nums.size()) {
            ans.push_back(finalAns);
            return ;
        }
        //take
        finalAns.push_back(nums[index]);
        subsetsRecursion(nums, index+1, finalAns, ans);
        //not take
        finalAns.pop_back();
        subsetsRecursion(nums, index+1, finalAns, ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> finalAns;
        vector<vector<int>> ans;
        subsetsRecursion(nums, 0, finalAns, ans);
        return ans;
    }
};
