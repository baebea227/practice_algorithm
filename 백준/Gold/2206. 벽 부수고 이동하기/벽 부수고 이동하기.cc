#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> grid;
bool visited[1001][1001][2];
int N, M;

struct Node {
    int x, y, broken;
};

int bfs() {
    queue<Node> q;
    q.push(Node{0, 0, 0});
    visited[0][0][0] = true;
    int dist = 1;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!q.empty()) {
        int qSize = q.size();
        for(int i=0; i<qSize; i++) {
            auto qFront = q.front(); q.pop();
            if(qFront.x == N-1 && qFront.y == M-1) return dist;
            
            for(int j=0; j<4; j++) {
                int nx = qFront.x + dx[j];
                int ny = qFront.y + dy[j];
    
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
    
                if(grid[nx][ny] == '0' && !visited[nx][ny][qFront.broken]) {
                    q.push({nx, ny, qFront.broken});
                    visited[nx][ny][qFront.broken] = true;
                }
                if(grid[nx][ny] == '1' && qFront.broken == 0 && !visited[nx][ny][1]) {
                    q.push({nx, ny, 1});
                    visited[nx][ny][1] = true;
                }
            }
        }
        dist++;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    grid.resize(N);
    for(int i=0; i<N; i++) cin >> grid[i];

    cout << bfs() << '\n';
}