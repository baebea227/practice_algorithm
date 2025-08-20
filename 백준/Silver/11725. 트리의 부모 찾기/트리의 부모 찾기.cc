#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> result;
vector<bool> visited;

void dfs(int currNode) {
    visited[currNode] = true;

    for (int nextNode : graph[currNode]) {
        if(!visited[nextNode]) {
            result[nextNode] = currNode;
            dfs(nextNode);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    graph.resize(N+1);
    result.resize(N+1);
    visited.resize(N+1);

    for(int i=1; i<N; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    for(int i=2; i<=N; i++) {
        cout << result[i] << '\n';
    }
}