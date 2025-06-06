#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> arr(n, vector<int>(m));
    queue<pair<int, int>> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    int cnt = -1;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while(!q.empty()){
        int qSize = q.size();
        for (int i=0; i<qSize; i++) {
            for (int j=0; j<4; j++) {
                int nx = q.front().first + dx[j];
                int ny = q.front().second + dy[j];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == 0) {
                    arr[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            q.pop();
        }
        cnt++;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << cnt << '\n';
}