class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxHeap;             // Sort based on best profit
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;     // Sort based on min capital to start

        int n = profits.size();
        for (int i = 0; i < n; i++) {
            if (capital[i] <= w) {
                maxHeap.push(profits[i]);
            }
            else {
                minHeap.push({capital[i], profits[i]});
            }
        }

        int ans = w;
        while (k--) {
            if (!maxHeap.empty()) {
                ans += maxHeap.top();
                maxHeap.pop();
            }

            while (!minHeap.empty() && minHeap.top().first <= ans) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
        }

        return ans;
    }
};