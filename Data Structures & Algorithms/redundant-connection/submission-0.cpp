class Solution {
public:
    class DSU {
        public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n + 1);
            size.resize(n + 1, 1);

            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (x == parent[x]) return x;
            return (parent[x] = find(parent[x]));
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) return;

            if (size[a] < size[b]) {
                swap(a, b);
            }

            parent[b] = a;
            size[a] += size[b];
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU x(n);
        int n1, n2;

        for (auto& edge : edges) {
            n1 = edge[0];
            n2 = edge[1];

            if (x.find(n1) == x.find(n2)) {
                return edge;
            }
            x.unite(n1, n2);
        }
        return {};
    }
};
