class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int node) {
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(adj, visited, neighbor);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);

        int a, b;
        for (auto& edge : edges) {
            a = edge[0];
            b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int cc = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cc++;
                dfs(adj, visited, i);
            }
        }
        return cc;
    }
};
