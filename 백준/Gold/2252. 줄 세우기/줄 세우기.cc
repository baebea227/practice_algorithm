#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n);
    vector<int> inDeg(n, 0);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        inDeg[b]++;
    }
    
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(inDeg[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur+1 << ' ';
        for(int next : graph[cur]) {
            if(--inDeg[next] == 0) {
                q.push(next);
            }        
        }
        cnt++;
    }

    if(cnt < n) {
        // cycle
    }

    cout << '\n';
}