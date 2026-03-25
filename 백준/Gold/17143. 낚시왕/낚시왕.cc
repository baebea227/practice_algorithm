#include <bits/stdc++.h>
using namespace std;

struct pos {
    int r, c;
};

struct Shark {
    int speed;
    int dir;
    int size;
};

pos move(pos cur, Shark& shark, int row, int col) {
    int s = shark.speed;
    int d = shark.dir;

    // up, down, right, left
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    s = (d < 2) ? s % ((row - 1) * 2) : s % ((col - 1) * 2);

    while(s > 0) {
        int nr = cur.r + dr[d];
        int nc = cur.c + dc[d];

        if(nr < 0 || nr >= row || nc < 0 || nc >= col) {
            d = (d % 2 == 0) ? d + 1 : d - 1;
            continue;
        }

        cur.r = nr;
        cur.c = nc;
        s--;
    }

    shark.dir = d;
    return cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int row, col, m;
    cin >> row >> col >> m;

    vector<vector<Shark>> board(row, vector<Shark>(col, {0, 0, 0}));
    vector<vector<Shark>> temp(row, vector<Shark>(col));
    
    for(int i=0; i<m; i++) {
        int r, c, speed, dir, size;
        cin >> r >> c >> speed >> dir >> size;
        board[r-1][c-1] = {speed, dir-1, size};
    }
    
    int ans = 0;
    
    for(int t=0; t<col; t++) { // 1. Man moves
        // 2. Catch
        for(int j=0; j<row; j++) {
            if(board[j][t].size > 0) {
                ans += board[j][t].size;
                board[j][t] = {0, 0, 0};
                break;
            }
        }
        
        // 3. Sharks move
        fill(temp.begin(), temp.end(), vector<Shark>(col, {0, 0, 0}));
        for(int j=0; j<col; j++) {
            for(int k=0; k<row; k++) {
                if(board[k][j].size > 0) {
                    pos next = move({k, j}, board[k][j], row, col);
    
                    if(temp[next.r][next.c].size < board[k][j].size) {
                        temp[next.r][next.c] = board[k][j];
                    }
                }
            }
        }
        swap(board, temp);
    }

    cout << ans << '\n';
}