#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> items(n);
    for(int i=0; i<n; i++) {
        cin >> items[i];
    }

    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for(int i=0; i<r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--; b--;
        dist[a][b] = min(dist[a][b], l);
        dist[b][a] = min(dist[b][a], l);
    }
    for(int i=0; i<n; i++) {
        dist[i][i] = 0;
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int answer = 0;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=0; j<n; j++) {
            if(dist[i][j] <= m) {
                sum += items[j];
            }
        }
        answer = max(answer, sum);
    }

    cout << answer << '\n';
}