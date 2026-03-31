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
        int j = index+1;
        while (j < nums.size() && nums[j] == nums[index])j++;
        subsetsRecursion(nums, j, finalAns, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> finalAns;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        subsetsRecursion(nums, 0, finalAns, ans);
        return ans;
    }
};
