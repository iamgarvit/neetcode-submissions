class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], 'A' + i});
            }
        }
        queue<pair<char, pair<int, int>>> q;
        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            if (!q.empty()) {
                while (!q.empty() && q.front().second.second == time) {
                    int freq = q.front().second.first;
                    char el = q.front().first;
                    maxHeap.push({freq, el});
                    q.pop();
                }
            }

            if (maxHeap.empty()) {
                time++;
                continue;
            }

            int p = maxHeap.top().first;
            char c = maxHeap.top().second;
            maxHeap.pop();
            p--;
            if (p > 0) {
                q.push({c, {p, time + n + 1}});
            }
            time++;
        }
        return time;
    }
};
