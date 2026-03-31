class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>> pq;
int totalSize;
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0 ; i < nums.size() ; i++) {
            if (pq.size() < k) pq.push(nums[i]);
            else if (pq.size() >= k && pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        totalSize = k;
    }
    
    int add(int val) {
        if (pq.size() >= totalSize && pq.top() < val) {
            pq.pop();
            pq.push(val);
        } else if (pq.size() < totalSize) pq.push(val);
        return pq.size() ? pq.top() : -1;
    }
};
