#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> indeg(n, 0);
    for(int i=0; i<m; i++) {
        int t;
        cin >> t;

        int a;
        cin >> a;
        a--;

        for(int j=1; j<t; j++) {
            int b;
            cin >> b;
            b--;

            graph[a].push_back(b);
            indeg[b]++;
            a = b;
        }
    }

    queue<int> q;
    for(int i=0; i<n; i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        ans.push_back(curr);

        for(int next : graph[curr]) {
            if(--indeg[next] == 0) {
                q.push(next);
            }
        }
    }

    if(ans.size() != n) {
        cout << 0 << '\n';
    } else {
        for(int i : ans) {
            cout << i+1 << '\n';
        }
    }
}