#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[1000][1000];
bool visited[1000][1000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int n, int m, int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    map[x][y] = 0;

    while(!q.empty()) {
        auto qFront = q.front();
        x = qFront.first;
        y = qFront.second;
        for (int j=0; j<4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(map[nx][ny] == 1 && !visited[nx][ny]) {
                    map[nx][ny] = map[x][y] + 1;
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    int targetX;
    int targetY;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
            visited[i][j] = false;

            if(map[i][j] == 2) {
                targetX = i;
                targetY = j;
            }
        }
    }

    bfs(n, m, targetX, targetY);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(!visited[i][j] && map[i][j] == 1) map[i][j] = -1;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}