#include <iostream>
#include <vector>
#include <deque>
using namespace std;

const int INF = 1e9;

int solve() {
    int N, K;
    cin >> N >> K;
    
    deque<int> dq;
    vector<int> dist(100001, INF);

    dq.push_back(N);
    dist[N] = 0;

    while(!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        if(cur == K) return dist[cur];
        
        int next = cur*2;
        if(next < 100001 && dist[next] > dist[cur]) {
            dq.push_front(next);
            dist[next] = dist[cur];
        }
        
        next = cur-1;
        if(next >= 0 && dist[next] > dist[cur] + 1) {
            dq.push_back(next);
            dist[next] = dist[cur] + 1;
        }

        next = cur+1;
        if(next < 100001 && dist[next] > dist[cur] + 1) {
            dq.push_back(next);
            dist[next] = dist[cur] + 1;
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << solve() << '\n';

    return 0;
}