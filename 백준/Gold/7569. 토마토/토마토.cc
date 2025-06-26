#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, n, h;
    cin >> m >> n >> h;
    
    vector<vector<vector<int>>> board(h, vector<vector<int>>(n, vector<int>(m)));
    vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(n, vector<bool>(m, false)));
    queue<tuple<int, int, int>> q;
    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    q.push({i, j, k});
                    visited[i][j][k] = true;
                }
            }
        }
    }

    int dz[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dx[6] = {0, 0, 0, 0, 1, -1};
    int cnt = -1;
    while(!q.empty()) {
        int qSize = q.size();
        for (int i=0; i<qSize; i++) {
            auto [z, y, x] = q.front();
            for (int j=0; j<6; j++) {
                int nz = z + dz[j];
                int ny = y + dy[j];
                int nx = x + dx[j];
                if (nz < h && nz >= 0 && ny < n && ny >= 0 && nx < m && nx >= 0) {
                    if (!visited[nz][ny][nx] && board[nz][ny][nx] == 0) {
                        q.push({nz, ny, nx});
                        visited[nz][ny][nx] = true;
                        board[nz][ny][nx] = 1;
                    }
                }
            }
            q.pop();
        }
        cnt++;
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                if (board[i][j][k] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << cnt << '\n';
}