class Solution {
public:
    bool detectCycle(vector<vector<int>>& adj, vector<int>& visited, int node, int parent) {
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            if (visited[neighbor])  return true;
            if (detectCycle(adj, visited, neighbor, node))  return true;;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 0);
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        if (detectCycle(adj, visited, 0, -1))   return false;
        for (int i = 0; i < n; i++) {
            if (!visited[i])    return false;
        }

        return true;
    }
};
