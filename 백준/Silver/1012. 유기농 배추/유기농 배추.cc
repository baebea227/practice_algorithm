#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<bool>>& board, int x, int y) {
    board[x][y] = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && board[nx][ny]) DFS(board, nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int nt;
    cin >> nt;
    
    for (int t=0; t<nt; t++) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<bool>> board(m, vector<bool> (n, 0));

        for (int i=0; i<k; i++) {
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }
        
        int cnt = 0;
        for(int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if(board[i][j]) {
                    DFS(board, i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}