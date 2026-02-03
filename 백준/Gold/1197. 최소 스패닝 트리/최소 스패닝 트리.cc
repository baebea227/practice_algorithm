#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int>& parent) {
    if(parent[x] != x)
        parent[x] = find(parent[x], parent);
    return parent[x];
}

bool unite(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);
    if(a == b) return false;
    parent[b] = a;
    return true;
}

struct Edge {
    int u, v, w;
};

int main() {
    int n;
    cin >> n;
    vector<int> parent(n);
    for(int i=0; i<n; i++) {
        parent[i] = i;
    }
    
    int m;
    cin >> m;
    vector<Edge> edges;

    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u-1, v-1, w});
    }

    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.w < b.w;
    });

    int totalWeight = 0;
    int cnt = 0;

    for(auto& edge : edges) {
        if(unite(edge.u, edge.v, parent)) {
            totalWeight += edge.w;
            if(++cnt == n-1) break;
        }
    }

    cout << totalWeight << '\n';
}