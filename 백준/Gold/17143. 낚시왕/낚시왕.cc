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

    vector<Shark> Sharks(m);
    vector<vector<int>> board(row, vector<int>(col, -1));
    vector<vector<int>> temp(row, vector<int>(col, -1));
    
    for(int i=0; i<m; i++) {
        int r, c, speed, dir, size;
        cin >> r >> c >> speed >> dir >> size;
        board[r-1][c-1] = i;
        Sharks[i] = {speed, dir-1, size};
    }
    
    int ans = 0;
    
    for(int t=0; t<col; t++) { // 1. Man moves
        // 2. Catch
        for(int i=0; i<row; i++) {
            if(board[i][t] != -1) {
                ans += Sharks[board[i][t]].size;
                board[i][t] = -1;
                break;
            }
        }
        
        // 3. Sharks move
        for(int i=0; i<row; i++) fill(temp[i].begin(), temp[i].end(), -1);
        for(int r=0; r<row; r++) {
            for(int c=0; c<col; c++) {
                if(board[r][c] != -1) {
                    pos next = move({r, c}, Sharks[board[r][c]], row, col);
                    int target = temp[next.r][next.c];
                    int curr = board[r][c];
    
                    if(target == -1 || Sharks[target].size < Sharks[curr].size) {
                        temp[next.r][next.c] = curr;
                    }
                }
            }
        }
        swap(board, temp);
    }

    cout << ans << '\n';
}