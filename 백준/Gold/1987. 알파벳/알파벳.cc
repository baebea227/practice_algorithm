#include <iostream>
using namespace std;

int R, C, result;
int board[21][21];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int num, int length) {
    result = max(result, length);

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if(num & board[nx][ny]) continue;

        dfs(nx, ny, num | board[nx][ny], length+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    for(int i=0; i<R; i++) {
        string line;
        cin >> line;
        for(int j=0; j<C; j++) {
            board[i][j] = 1 << (line[j]-'A');
        }
    };

    dfs(0, 0, board[0][0], 1);

    cout << result << '\n';
}