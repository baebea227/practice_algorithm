#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(vector<vector<bool>>& visited, const vector<string>& board, int x, int y) {
    int n = board.size();
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()) {
        for (int i=0; i<4; i++) {
            int nx = q.front().first + dx[i];
            int ny = q.front().second + dy[i];
            if(nx < n && nx >= 0 && ny < n && ny >= 0) {
                if(!visited[nx][ny] && board[nx][ny] == board[x][y]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        q.pop();
    }
}

int boardSearch(const vector<string>& board) {
    int cnt = 0;
    int n = board.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(!visited[i][j]) {
                bfs(visited, board, i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<string> board(n);
    for (int i=0; i<n; i++) {
        cin >> board[i];
    }
    
    cout << boardSearch(board) << " ";
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(board[i][j] == 'R') board[i][j] = 'G';
        }
    }
    cout << boardSearch(board) << '\n';
}