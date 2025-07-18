#include <iostream>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[600][600];
char campus[600][600];
int cnt;

void dfs(int n, int m, int x, int y) {
    visited[x][y] = true;
    if(campus[x][y] == 'P') cnt++;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if(!visited[nx][ny] && campus[nx][ny] != 'X') {
                dfs(n, m, nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    int a, b;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> campus[i][j];
            if(campus[i][j] == 'I') {
                a = i;
                b = j;
            }
        }
    }
    dfs(n, m, a, b);
    if(cnt) cout << cnt << '\n';
    else cout << "TT" << '\n';
}