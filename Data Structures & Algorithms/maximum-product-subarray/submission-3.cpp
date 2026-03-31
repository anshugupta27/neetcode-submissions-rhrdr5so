class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int posProd = nums[0], negProd = nums[0], maxProd = nums[0];
        for (int i = 1 ; i < nums.size() ; i++) {
            int temp = posProd;
            posProd = max({nums[i], posProd*nums[i], negProd*nums[i]});
            negProd = min({nums[i], negProd*nums[i], temp*nums[i]});
            maxProd = max({maxProd, negProd, posProd});
        }
        return maxProd;
    }
};
