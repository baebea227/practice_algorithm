#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> visited(n+1, false);
    vector<vector<int>> graph(n+1);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    int cnt = 0;
    for(int i=1; i<n+1; i++) {
        if(!visited[i]) {
            q.push(i);
            visited[i] = true;
            cnt++;
        }
        while(!q.empty()) {
            for(int j=0; j<graph[q.front()].size(); j++) {
                int curr = graph[q.front()][j];
                if(!visited[curr]) {
                    q.push(curr);
                    visited[curr] = true;
                }
            }
            q.pop();
        }
    }
    cout << cnt << '\n';
}