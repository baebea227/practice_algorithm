#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int board[20][20];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct Shark {
    int x, y, size = 2, eaten = 0;
};

struct Node {
    int dist, x, y;
    bool operator<(const Node &other) const {
        if (dist != other.dist) return dist > other.dist;
        if (x != other.x) return x > other.x;
        return y > other.y;    
    }
};

int bfs(Shark& shark) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    priority_queue<Node> pq;
    
    pq.push({0, shark.x, shark.y});
    visited[shark.x][shark.y] = true;
    
    while(!pq.empty()) {
        auto [d, x, y] = pq.top(); pq.pop();

        if(board[x][y] > 0 && board[x][y] < shark.size) {
            shark.x = x; shark.y = y;
            shark.eaten++;
            if(shark.eaten == shark.size) {
                shark.size++;
                shark.eaten = 0;
            }
            board[x][y] = 0;
            return d;
        }
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || board[nx][ny] > shark.size) continue;

            visited[nx][ny] = true;
            pq.push({d+1, nx, ny});
        }
    }
    return -1;
}

void solve() {
    cin >> N;
    
    Shark shark;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                shark.x = i; shark.y = j;
                board[i][j] = 0;
            }
        }
    }
    
    int time = 0;
    while(true) {
        int t = bfs(shark);
        if(t == -1) break;
        time += t;
    }

    cout << time << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}