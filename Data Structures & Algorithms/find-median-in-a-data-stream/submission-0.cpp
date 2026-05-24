class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (minHeap.empty()) {
            minHeap.push(num);
        }
        else if (num > minHeap.top()) {
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }

        if (abs((int)minHeap.size() - (int)maxHeap.size()) > 1) {
            int minS = minHeap.size();
            int maxS = maxHeap.size();

            if (minS > maxS) {
                int x = minHeap.top();
                minHeap.pop();
                maxHeap.push(x);
            }
            else {
                int x = maxHeap.top();
                maxHeap.pop();
                minHeap.push(x);
            }
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return ((minHeap.top() + maxHeap.top())/2.0);
        }

        if (minHeap.size() > maxHeap.size()) {
            return (double)minHeap.top();
        }
        return (double)maxHeap.top();
    }
};
