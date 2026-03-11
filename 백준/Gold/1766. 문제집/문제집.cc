#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> indegree(n, 0);
    vector<vector<int>> graph(n);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        graph[--a].push_back(--b);
        indegree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0)
            pq.push(i);
    }

    while(!pq.empty()) {
        int curr = pq.top();
        pq.pop();

        cout << curr + 1 << " ";

        for(int next : graph[curr]) {
            if(--indegree[next] == 0) {
                pq.push(next);
            }
        }
    }

    cout << '\n';
}