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
                auto[x, y] = q.front();
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == 0) {
                    arr[nx][ny] = arr[x][y] + 1;
                    q.push({nx, ny});
                }
            }
            q.pop();
        }
    }

    int maxXY = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }
            else {
                maxXY = max(maxXY, arr[i][j]);
            }
        }
    }
    cout << maxXY - 1 << '\n';
}