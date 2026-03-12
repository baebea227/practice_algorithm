#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<bool> visited;
vector<bool> finished;
int cnt;

void dfs(int n) {
    visited[n] = true;
    int next = parent[n];

    if(!visited[next]) {
        dfs(next);
    }
    else if(!finished[next]) {
        while(next != n) {
            next = parent[next];
            cnt++;
        }
        cnt++;
    }
    
    finished[n] = true;
}

void solve() {
    int n;
    cin >> n;

    parent.resize(n);
    visited.assign(n, false);
    finished.assign(n, false);
    cnt = 0;
    
    for(int i=0; i<n; i++) {
        cin >> parent[i];
        parent[i]--;
    }
    
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    cout << n - cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();
}