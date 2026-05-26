class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses);

        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            cnt++;
            ans.push_back(course);

            for (int neighbor : adj[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (cnt == numCourses)  return ans;
        return {};
    }
};
