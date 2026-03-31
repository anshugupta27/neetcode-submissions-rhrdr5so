class Solution {
public:
    bool isValid(vector<int>& piles, int banana, int hour) {
        int requiredHour = 0;
        for (auto it: piles) {
            int rem = it % banana; // 1
            requiredHour += it / banana; //
            if (rem) requiredHour += 1;
            if (requiredHour > hour) return false;
        }
        return true;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBanana = 0, minBanana = INT_MAX;
        for (auto it: piles) maxBanana = max(maxBanana, it);
        int low = 1, high = maxBanana; // low = 0, high = 10
        while (low <= high) {
            int mid = low + (high-low)/2; // mid = 5, 2
            if (isValid(piles, mid, h)) {
                minBanana = min(mid, minBanana); //2
                high = mid - 1; // high = 4, 1
            } else low = mid + 1;
        }
        return minBanana;
    }
};
