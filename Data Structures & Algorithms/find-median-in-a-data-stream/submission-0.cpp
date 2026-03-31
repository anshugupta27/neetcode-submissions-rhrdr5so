class MedianFinder {
public:
priority_queue<double> maxHeap;
        priority_queue<double,vector<double>, greater<double>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // max heap -> have the smallest values
        // min heap -> having all the greatest values
        // top value of min heap should be greater than max value in max heap
        // 1 2 3 4 5 6 7 8
        // 1 to 4 in max heap and 5 to 8 in min heap
        
        // Case 1: if both heaps are empty
        // Case 2: if any one of the heap is empty
        // Case 3 : if none of the heap is empty
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        else if (maxHeap.size() < minHeap.size()) return minHeap.top();
        else {
            return double(maxHeap.top() + minHeap.top()) /2.0;
        }
        
    }
};
