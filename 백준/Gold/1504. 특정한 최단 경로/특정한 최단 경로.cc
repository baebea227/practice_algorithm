#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int INF = 200000 * 1000;

void solve() {
    int N, E;
    cin >> N >> E;
    
    vector<vector<pair<int, int>>> graph(N+1); // graph[start] = {end, dist}
    for(int i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int v1, v2;
    cin >> v1 >> v2;
    
    map<pair<int,int>, int> dists; // dists[{start, end}] = dist
    
    for(int start : {1, v1, v2}) {
        priority_queue<pair<int, int>> pq; // {-dist, node}
        vector<int> dist(N+1, INF);
        
        pq.push({0, start});
        dist[start] = 0;
        
        while(!pq.empty()) {
            auto [curDist, curNode] = pq.top();
            curDist = -curDist;
            pq.pop();

            if(curDist > dist[curNode]) continue;

            for(auto [nextNode, nextDist] : graph[curNode]) {
                nextDist += curDist;
                if(nextDist < dist[nextNode]) {
                    dist[nextNode] = nextDist;
                    pq.push({-nextDist, nextNode});
                }
            }
        }

        dists[{start, v1}] = dist[v1];
        dists[{start, v2}] = dist[v2];
        dists[{start, N}] = dist[N];
    }

    int answer = min(dists[{1, v1}] + dists[{v2, N}], dists[{1,v2}] + dists[{v1, N}]) + dists[{v1, v2}];

    if(answer >= INF) cout << -1 << '\n';
    else cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}