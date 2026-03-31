class Solution {
public:
    int hammingWeight(uint32_t n) {
        int countOne = 0 ;
    while (n != 0) {
    if (n & 1) countOne++;
       n = n >> 1;
    }
    return countOne;
    }
};
