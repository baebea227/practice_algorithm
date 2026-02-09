#include <bits/stdc++.h>
using namespace std;

struct pos {
    int rx, ry, bx, by;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<vector<char>> board;

pos move(int j, pos curr) {
    pos next = curr;

    while(board[next.ry + dy[j]][next.rx + dx[j]] != '#' && board[next.ry][next.rx] != 'O') {
        next.ry += dy[j];
        next.rx += dx[j];
    }

    while(board[next.by + dy[j]][next.bx + dx[j]] != '#' && board[next.by][next.bx] != 'O') {
        next.by += dy[j];
        next.bx += dx[j];
    }

    if(next.ry == next.by && next.rx == next.bx) {
        if(board[next.ry][next.rx] != 'O') {
            if (abs(next.rx - curr.rx) + abs(next.ry - curr.ry) > abs(next.bx - curr.bx) + abs(next.by - curr.by)) {
                next.rx -= dx[j];
                next.ry -= dy[j];
            } else {
                next.bx -= dx[j];
                next.by -= dy[j];
            }
        }
    }

    return next;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    board.assign(n, vector<char>(m));
    pos start;

    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                start.ry = i; start.rx = j;
                board[i][j] = '.';
            }
            else if(board[i][j] == 'B') {
                start.by = i; start.bx = j;
                board[i][j] = '.';
            }
        }
    }

    queue<pos> q;
    q.push(start);

    bool visited[10][10][10][10] = {false, };
    visited[start.ry][start.rx][start.by][start.bx] = true;

    int cnt = 1;
    while(!q.empty()) {
        int qSize = q.size();
        for(int i=0; i<qSize; i++) {
            pos curr = q.front();
            q.pop();

            for(int j=0; j<4; j++) {
                pos next = move(j, curr);

                if(board[next.by][next.bx] == 'O') continue;

                if(board[next.ry][next.rx] == 'O') {
                    cout << cnt << '\n';
                    return 0;
                }

                if(visited[next.ry][next.rx][next.by][next.bx]) continue;

                q.push(next);
                visited[next.ry][next.rx][next.by][next.bx] = true;
            }
        }

        cnt++;
        if(cnt > 10) break;
    }

    cout << -1 << '\n';
}