class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> occurence;
        int maxSeqLen = 0, n = nums.size();
        for (int i = 0 ; i < n ; i++) {
            occurence[nums[i]]++;
        }
        for (auto it : occurence) {
            if (occurence.find(it.first-1) == occurence.end()) {
                int maxLoop = n, next = it.first;
                while (maxLoop--) {
                    if (occurence.find(next) == occurence.end()) break;
                    next++;
                }
                maxSeqLen = max(maxSeqLen, n-maxLoop-1);
            }
        }
        return maxSeqLen;
            
    }
};
