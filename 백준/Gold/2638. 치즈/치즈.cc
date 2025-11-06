#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
vector<vector<int>> board;

vector<vector<bool>> findAirBfs() {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        for(int k=0; k<4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

            if(!visited[ny][nx] && board[ny][nx] == 0) {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }

    }

    return visited;
}

bool melt(vector<vector<bool>>& airVisited) {
    vector<pair<int, int>> melts;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] == 1) {
                int cnt = 0;

                for(int k=0; k<4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                    
                    if(airVisited[ny][nx])
                        cnt++;
                }

                if(cnt >= 2)
                melts.push_back({i, j});
            }
        }
    }

    for(auto [y, x] : melts)
        board[y][x] = 0;

    return !melts.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    board.resize(N, vector<int>(M));

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }

    int time = 0;
    while(true) {
        vector<vector<bool>> airVisited = findAirBfs();

        if(!melt(airVisited)) break;
        
        time++;
    }

    cout << time << '\n';

    return 0;
}