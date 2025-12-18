#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int s, e, t;
};

void solve() {
    int n, m, w;
    cin >> n >> m >> w;

    vector<Edge> edges;
    for(int i=0; i<m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        s--; e--;
        edges.push_back({s, e, t});
        edges.push_back({e, s, t});
    }

    for(int i=0; i<w; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        s--; e--;
        edges.push_back({s, e, -t});
    }

    vector<int> dist(n, 0);
    for(int i=0; i<n; i++) {
        bool updated = false;

        for(auto& edge : edges) {
            if(dist[edge.s] > dist[edge.e] + edge.t) {
                dist[edge.s] = dist[edge.e] + edge.t;
                updated = true;
                if(i == n-1) {
                    cout << "YES\n";
                    return;
                }
            }
        }

        if(!updated) break;
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) solve();
}