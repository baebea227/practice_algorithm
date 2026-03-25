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

    if (d == 0 || d == 1) { // up, down
        if (row > 1) {
            int cycle = (row - 1) * 2;
            
            int start = (d == 1) ? cur.r : cycle - cur.r;
            int next = (start + s) % cycle;

            if (next < row) {
                cur.r = next;
                d = 1;
            } else {
                cur.r = cycle - next;
                d = 0;
            }
        }
    } else { // right, left
        if (col > 1) {
            int cycle = (col - 1) * 2;
            
            int start = (d == 2) ? cur.c : cycle - cur.c;
            int next = (start + s) % cycle;

            if (next < col) {
                cur.c = next;
                d = 2;
            } else {
                cur.c = cycle - next;
                d = 3;
            }
        }
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
        fill(temp.begin(), temp.end(), vector<int>(col, -1));
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