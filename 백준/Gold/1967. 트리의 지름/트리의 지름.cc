#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<bool> visited;
int farNode, maxDist;

void dfs(int curNode, int curDist) {

    visited[curNode] = true;
    
    if(curDist > maxDist) {
        maxDist = curDist;
        farNode = curNode;
    }

    for(auto [nextNode, nextDist] : graph[curNode] ) {
        if(!visited[nextNode]) dfs(nextNode, curDist + nextDist);
    }
}

void solve() {
    int n;
    cin >> n;

    graph.resize(n+1);
    for(int i=0; i<n-1; i++) {
        int parent, child, dist;
        cin >> parent >> child >> dist;
        graph[child].push_back({parent, dist});
        graph[parent].push_back({child, dist});
    }

    visited.assign(n+1, false);
    dfs(1, 0);

    visited.assign(n+1, false);
    dfs(farNode, 0);

    cout << maxDist << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}