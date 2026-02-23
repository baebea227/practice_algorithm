#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> cost(n+1);
    for(int i=1; i<=n; i++) {
        cin >> cost[i];
    }
    
    vector<vector<int>> graph(n+1);
    vector<int> indeg(n+1, 0);
    for(int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        indeg[y]++;
    }

    int w;
    cin >> w;

    vector<int> dp(n+1);
    queue<int> q;

    for(int i=1; i<=n; i++) {
        if(indeg[i] == 0) {
            q.push(i);
            dp[i] = cost[i];
        }
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if(curr == w) break;

        for(int next : graph[curr]) {
            dp[next] = max(dp[next], dp[curr] + cost[next]);

            if(--indeg[next] == 0) {
                q.push(next);
            }
        }
    }

    cout << dp[w] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) solve();
}