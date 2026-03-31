class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>finalAns;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n ; i++) {
            while (i > 0 && nums[i] == nums[i-1]) i++;
            int left = i+1, right = nums.size()-1;
         while (left < right) {
            if (nums[left]+nums[right]+nums[i] == 0) {
                finalAns.push_back({nums[i], nums[left], nums[right]});
                left++, right--;
                while (left < right && nums[left] == nums[left-1]) left++;
            } else if (nums[left]+nums[right]+nums[i] < 0) left++;
            else right--;
           }

        }
        return finalAns;
    }
};
