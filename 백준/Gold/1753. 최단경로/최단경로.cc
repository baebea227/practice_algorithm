#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 3000001

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> graph(V+1);
    for(int i=0; i<E; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    
    vector<int> dist(V+1, INF);
    priority_queue<pair<int, int>> pq;

    dist[K] = 0;
    pq.push({0, K});

    while(!pq.empty()) {
        int currDist = -pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if(currDist > dist[currNode]) continue;
      
        for(auto next : graph[currNode]) {
            int nextNode = next.first;
            int nextDist = currDist + next.second;
            if(nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({-dist[nextNode], nextNode});
            }
        }
    }
    
    for(int i=1; i<=V; i++) {
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}