#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000001

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> graph(N+1);
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    int start, end;
    cin >> start >> end;

    vector<int> dist(N+1, INF);
    priority_queue<pair<int,int>> pq;

    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int currDist = -pq.top().first;
        int currNode = pq.top().second;
        pq.pop();
        
        if(currDist > dist[currNode]) continue;

        if(currNode == end) break;
        
        for(auto next : graph[currNode]) {
            int nextNode = next.first;
            int nextDist = currDist + next.second;
            if(nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({-nextDist, nextNode});
            }
        }
    }

    cout << dist[end] << '\n';
}