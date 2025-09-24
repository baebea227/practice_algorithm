#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<bool> visited;
pair<int,int> farthest; // {node, dist}

void dfs(int curNode, int curDist) {
    visited[curNode] = true;
    for(auto [nextNode, nextDist] : graph[curNode]) {
        if(visited[nextNode]) continue;
        
        nextDist += curDist;
        if(nextDist > farthest.second)
            farthest = {nextNode, nextDist};
        dfs(nextNode, nextDist);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    cin >> V;

    graph.resize(V+1);
    visited.assign(V+1, false);

    for(int i=0; i<V; i++) {
        int a;
        cin >> a;

        while(true) {
            int b;
            int dist;
            cin >> b;
            if(b == -1) break;
            cin >> dist;
            graph[a].push_back({b, dist});
        }
    }

    dfs(1, 0); // find farthest leaf node
    visited.assign(V+1, false);
    dfs(farthest.first, 0);

    cout << farthest.second << '\n';
}