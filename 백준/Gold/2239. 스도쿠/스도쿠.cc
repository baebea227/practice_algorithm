#include <bits/stdc++.h>
using namespace std;

const int N = 9;
const int M = 3;

int board[N][N];
bool row[N][N+1];
bool col[N][N+1];
bool square[N][N+1];

int calSquare(int x, int y) {
    return x/M*M + y/M;
}

bool dfs(int depth) {
    if(depth == N*N) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
        return true;
    }

    int x = depth/N; int y = depth%N;

    if(board[x][y] != 0) {
        return dfs((depth + 1));
    }
    else {
        int sq = calSquare(x, y);

        for(int i=1; i<=N; i++) {
            if(!row[x][i] && !col[y][i] && !square[sq][i]) {
                row[x][i] = col[y][i] = square[sq][i] = true;
                board[x][y] = i;
                if(dfs(depth + 1)) return true;
                board[x][y] = 0;
                row[x][i] = col[y][i] = square[sq][i] = false;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<N; j++) {
            board[i][j] = s[j] - '0';
            if(board[i][j] != 0) {
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                square[calSquare(i, j)][board[i][j]] = true;
            }
        }
    }

    dfs(0);
}