class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0, currentIndex = 0, maxFarthest = 0;
        for (int i = 0 ; i < nums.size()-1 ; i++) {
            maxFarthest = max(maxFarthest, i+nums[i]);
            if (i == currentIndex) {
                jump++;
                currentIndex = maxFarthest;
            }
        }
        return jump;
    }
};
