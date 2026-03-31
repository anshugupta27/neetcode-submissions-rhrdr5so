class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0, high = nums.size()-1, minPotentialAns = INT_MAX; 
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] <= nums[high]) {
                minPotentialAns = min(minPotentialAns, nums[mid]);
                high = mid - 1;
            } else if (nums[mid] >= nums[low]) {
                minPotentialAns = min(minPotentialAns, nums[low]);
                low = mid + 1;
            }
        }
        return minPotentialAns;
    }
};
