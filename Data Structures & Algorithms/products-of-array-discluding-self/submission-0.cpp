class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        vector<int> finalAns;
        int prod = 1;
        for (int i = 0 ; i < n ; i++) {
            prefix[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for (int i = n-1 ; i >= 0 ; i--) {
            suffix[i] = prod;
            prod *= nums[i];
        }
        for (int i = 0 ; i < n ; i++) {
            finalAns.push_back(prefix[i] * suffix[i]) ;
        }
        return finalAns;

    }
};
