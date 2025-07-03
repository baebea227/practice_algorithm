#include <iostream>
using namespace std;

bool visited[500][500] = {false};
int board[500][500];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int maxSum = 0;
int n, m;

void dfs(int y, int x, int depth, int sum) {
    if(depth == 4) {
        if(maxSum < sum) maxSum = sum;
        return;
    }
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx]) continue;

        visited[ny][nx] = true;
        dfs(ny, nx, depth+1, sum+board[ny][nx]);
        visited[ny][nx] = false;
    }
}

void checkT(int y, int x) {
    for(int i=0; i<4; i++) {
        int sum = board[y][x];
        for(int j=0; j<3; j++) {
            int ny = y + dy[(i+j)%4];
            int nx = x + dx[(i+j)%4];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            sum += board[ny][nx];
        }
        if(maxSum < sum) maxSum = sum;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            cin >> board[y][x];
        }
    }

    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            visited[y][x] = true;
            dfs(y, x, 1, board[y][x]);
            visited[y][x] = false;
            checkT(y, x);
        }
    }
    cout << maxSum << '\n';
}