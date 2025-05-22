#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void DFS(const vector<vector<int>>& graph, vector<bool>& visited, int curr) {
    visited[curr] = true;
    cout << curr << " ";

    for (int next : graph[curr]) {
        if(!visited[next]) {
            DFS(graph, visited, next);
        }
    }
}

void BFS(const vector<vector<int>>& graph, vector<bool>& visited, int curr) {
    queue<int> q;
    q.push(curr);
    visited[curr] = true;

    while (!q.empty()) {
        curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int next : graph[curr]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, start;
    cin >> n >> m >> start;
    
    vector<vector<int>> graph(n+1);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> visited(n+1, false);
    DFS(graph, visited, start);
    cout << '\n';

    visited.assign(n+1, false);
    BFS(graph, visited, start);
}