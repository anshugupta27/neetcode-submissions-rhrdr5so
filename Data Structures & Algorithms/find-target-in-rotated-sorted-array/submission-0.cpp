class Solution {
public:
    int search(vector<int>& nums, int target) {
          int low = 0, high = nums.size()-1, minPotentialAns = INT_MAX; 
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (target == nums[mid]) return mid;
            else if (nums[mid] <= nums[high]) {
                if (target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else high = mid - 1;
            } else if (nums[mid] >= nums[low]) {
                if (target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                } else low = mid + 1;
            }
        }
        return -1;
    }
};
