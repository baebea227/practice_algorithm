#include <bits/stdc++.h>
using namespace std;

int n;
int answer = 0;

void move(int dir, vector<vector<int>>& board) {
    for(int i=0; i<n; i++) {
        vector<int> line;
        for(int j=0; j<n; j++) {
            if (dir == 0) {
                if (board[i][j] != 0) line.push_back(board[i][j]);
            } else if (dir == 1) {
                if (board[i][n-1-j] != 0) line.push_back(board[i][n-1-j]);
            } else if (dir == 2) {
                if (board[j][i] != 0) line.push_back(board[j][i]);
            } else if (dir == 3) {
                if (board[n-1-j][i] != 0) line.push_back(board[n-1-j][i]);
            }
        }

        vector<int> merged;
        for(int i=0; i<line.size(); i++) {
            if(i+1 < line.size() && line[i] == line[i+1]) {
                merged.push_back(line[i]*2);
                i++;
            }
            else {
                merged.push_back(line[i]);
            }
        }
    
        while(merged.size() < n) merged.push_back(0);
        for(int j=0; j<n; j++) {
            if(dir == 0) board[i][j] = merged[j];
            else if(dir == 1) board[i][n-1-j] = merged[j];
            else if(dir == 2) board[j][i] = merged[j];
            else if(dir == 3) board[n-1-j][i] = merged[j];
        }
    }
}

void dfs(int depth, vector<vector<int>>& board) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            answer = max(answer, board[i][j]);
        }
    }

    if(depth == 5) return;

    for(int i=0; i<4; i++) {
        vector<vector<int>> next = board;
        move(i, next);
        dfs(depth+1, next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, board);
    cout << answer << '\n';
}