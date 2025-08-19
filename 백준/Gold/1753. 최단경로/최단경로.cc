#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 3000001

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int V, E, K;
    cin >> V >> E; // 노드 개수, 간선 개수
    cin >> K; // 출발노드
    vector<pair<int, int>> graph[V+1]; // graph[출발노드] = {도착노드, 가중치}
    for(int i=0; i<E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w}); // 노드 1부터 시작
    }
    
    vector<int> dist(V+1, INF); // dist[도착노드] = 총 거리
    priority_queue<pair<int, int>> pq; // (-거리, 노드) 삽입/삭제 시 음수 붙임

    dist[K] = 0;
    pq.push({0, K});
    while(!pq.empty()) {
        int currDist = -pq.top().first;
        int currNode = pq.top().second;
        pq.pop();
        for(auto next : graph[currNode]) { // 현재 노드에 연결된 다음 노드 탐색
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