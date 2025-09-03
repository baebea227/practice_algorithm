#include <iostream>
#include <vector>
using namespace std;

const int INF = 99999;

vector<pair<int,int>> homes;
vector<pair<int,int>> shops;
int N, M;
int minDist = INF;

vector<int> seq;
void dfs(int depth) {
    if(depth == M) {
        int total=0;
        for(pair<int,int> h : homes) {
            int dist = INF;
            for(int shopIndex : seq) {
                int shopY = shops[shopIndex].first;
                int shopX = shops[shopIndex].second;
                dist = min(dist, abs(h.first-shopY)+abs(h.second-shopX));
            }
            total += dist;
        }
        minDist = min(minDist, total);
        return;
    }

    int shopCount = shops.size();
    for(int i=0; i<shopCount; i++) {
        if(!seq.empty() && i<=seq.back()) continue;
        seq.push_back(i);
        dfs(depth+1);
        seq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int n;
            cin >> n;
            if(n == 1) homes.push_back({i, j});
            else if(n == 2) shops.push_back({i, j});
        }
    }

    dfs(0);
    
    cout << minDist << '\n';
}