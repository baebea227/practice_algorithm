#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> graph(n+1);
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b}); // dist, node
    }

    int A, B;
    cin >> A >> B;

    vector<int> dist(n+1, 1e9);
    vector<int> prev(n+1, -1);
    priority_queue<pair<int, int>> pq;

    dist[A] = 0;
    pq.push({0, A});

    while(!pq.empty()) {
        auto [currDist, currNode] = pq.top();
        currDist = -currDist;
        pq.pop();

        if(currDist > dist[currNode]) continue;

        for(auto [nextDist, nextNode] : graph[currNode]) {
            nextDist += currDist;
            if(nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                prev[nextNode] = currNode;
                pq.push({-nextDist, nextNode});
            }
        }
    }

    cout << dist[B] << '\n';

    vector<int> path;
    for(int i=B; i!=-1; i=prev[i]) 
        path.push_back(i);

    cout << path.size() << '\n';
    for(auto it = path.rbegin(); it != path.rend(); it++) cout << *it << " ";
    cout << '\n';

    return 0;
}