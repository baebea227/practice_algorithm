#include <iostream>
using namespace std;

int R, C, result;
string board[21];

bool seq[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int length) {
    result = max(result, length);
    seq[(board[x][y]-'A')] = true;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if(seq[(board[nx][ny]-'A')]) continue;

        dfs(nx, ny, length+1);
    }

    seq[(board[x][y]-'A')] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    for(int i=0; i<R; i++) cin >> board[i];

    dfs(0, 0, 1);

    cout << result << '\n';
}