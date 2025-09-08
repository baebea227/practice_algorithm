#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> map;
int N, M;

struct Node {
    int x, y, broken, dist;
};

int bfs() {
    queue<Node> q;
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    q.push(Node{0, 0, 0, 1});
    visited[0][0][0] = true;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!q.empty()) {
        Node qFront = q.front(); q.pop();

        if(qFront.x == N-1 && qFront.y == M-1) return qFront.dist;
        
        for(int j=0; j<4; j++) {
            int nx = qFront.x + dx[j];
            int ny = qFront.y + dy[j];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(map[nx][ny] == '0' && !visited[nx][ny][qFront.broken]) {
                q.push({nx, ny, qFront.broken, qFront.dist+1});
                visited[nx][ny][qFront.broken] = true;
            }
            if(map[nx][ny] == '1' && qFront.broken == 0 && !visited[nx][ny][1]) {
                q.push({nx, ny, 1, qFront.dist+1});
                visited[nx][ny][1] = true;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    map.resize(N);
    for(int i=0; i<N; i++) cin >> map[i];

    cout << bfs() << '\n';
}