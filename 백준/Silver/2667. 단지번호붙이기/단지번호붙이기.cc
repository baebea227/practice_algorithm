#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int BFS(vector<string>& board, int x, int y) {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    board[x][y] = '0';
    int cnt = 1;

    while(!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();

        for (int j=0; j<4; j++) {
            int nx = qx + dx[j];
            int ny = qy + dy[j];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size() && board[nx][ny] == '1') {
                q.push(make_pair(nx, ny));
                board[nx][ny] = '0';
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

    vector<int> result;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (board[i][j] == '1') {
                int bfs = BFS(board, i, j);
                result.push_back(bfs);
            }
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (int i : result) {
        cout << i << '\n';
    }
}