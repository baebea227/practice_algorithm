#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int N, M, X;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(N, INF);
    priority_queue<pair<int,int>> pq; // {dist, node}
    
    dist[X] = 0;
    pq.push({0, X});
    
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

    return dist;
}

void solve() {
    cin >> N >> M >> X;
    X--;
    
    vector<vector<pair<int, int>>> graph(N); // graph[start][index] = {next, dist}
    vector<vector<pair<int, int>>> rGraph(N); // graph[start][index] = {next, dist}
    
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1].push_back({b-1, c});
        rGraph[b-1].push_back({a-1,c});
    }
    
    vector<int> distFromX = dijkstra(graph);
    vector<int> distToX = dijkstra(rGraph);

    int result = 0;
    for(int i=0; i<N; i++) {
        result = max(result, (distFromX[i] + distToX[i]));
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}