#include <iostream>
#include <vector>
using namespace std;
   
    
void solve() {
    int R, C, T;
    cin >> R >> C >> T;
    
    vector<vector<int>> board(R, vector<int>(C, 0));
    vector<int> cleaner_Y;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> board[i][j];
        }
        if(board[i][0] == -1) cleaner_Y.push_back(i);
    }
    
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    
    while(T--) {
        vector<vector<int>> nextBoard(R, vector<int>(C, 0));

        // spread
        for(int y=0; y<R; y++) {
            for(int x=0; x<C; x++) {

                int n = board[y][x];
                nextBoard[y][x] += n;

                if(board[y][x] >= 5) {
                    for(int i=0; i<4; i++) {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if(ny < 0 || ny >= R || nx < 0 || nx >= C || board[ny][nx] == -1) continue;
                        nextBoard[ny][nx] += n/5;
                        nextBoard[y][x] -= n/5;
                    }
                }
            }
        }
        board = nextBoard;

        // cleaning
        for(int x=1; x<C; x++) { // left-right
            nextBoard[cleaner_Y[0]][x] = board[cleaner_Y[0]][x-1];
            nextBoard[cleaner_Y[1]][x] = board[cleaner_Y[1]][x-1];
        }
        for(int x=0; x<C-1; x++) { // right-left
            nextBoard[0][x] = board[0][x+1];
            nextBoard[R-1][x] = board[R-1][x+1];
        }
        for(int y=0; y<cleaner_Y[0]; y++) { // right-up
            nextBoard[y][C-1] = board[y+1][C-1];
        }
        for(int y=1; y<cleaner_Y[0]; y++) { // left-down
            nextBoard[y][0] = board[y-1][0];
        }
        for(int y=cleaner_Y[1]+1; y<R; y++) { // right-down
            nextBoard[y][C-1] = board[y-1][C-1];
        }
        for(int y=cleaner_Y[1]+1; y<R-1; y++) { // left-up
            nextBoard[y][0] = board[y+1][0];
        }

        nextBoard[cleaner_Y[0]][0] = -1;
        nextBoard[cleaner_Y[1]][0] = -1;

        nextBoard[cleaner_Y[0]][1] = 0;
        nextBoard[cleaner_Y[1]][1] = 0;  

        board=nextBoard;
    }

    int answer = 2;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            answer += board[i][j];
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}