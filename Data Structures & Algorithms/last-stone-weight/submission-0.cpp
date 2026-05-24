class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int num1 = maxHeap.top();
            maxHeap.pop();
            int num2 = maxHeap.top();
            maxHeap.pop();

            if (num1 == num2)   continue;
            maxHeap.push(num1 - num2);
        }
        
        if (maxHeap.size() == 0)    return 0;
        return maxHeap.top();
    }
};
