class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i = 0 ; i < nums.size() ; i++) {
            int  potentialAns = target - nums[i] ;
            if (mp.find(potentialAns) != mp.end()) return {mp[potentialAns], i};
            if (mp.find(nums[i]) == mp.end()) mp[nums[i]] = i;
        }
        return {};
    }
};
