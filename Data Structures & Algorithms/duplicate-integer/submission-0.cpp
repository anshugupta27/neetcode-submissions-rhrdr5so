class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>occurence;
        for (int i = 0 ; i < nums.size() ; i++) {
            occurence[nums[i]]++;
            if ( occurence[nums[i]] > 1 ) return true;
        }
        return false;

    }
};
