#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board;

void star(int n, int x, int y) {
    for(int i=n/3; i<n*2/3; i++) {
        for(int j=n/3; j<n*2/3; j++) {
            board[x+i][y+j] = ' ';
        }
    }
    if(n == 3) {
        return;
    }
    for(int i=x; i<x+n; i+=n/3) {
        for(int j=y; j<y+n; j+=n/3) {
            star(n/3, i, j);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    board.resize(N, vector<char>(N, '*'));
    star(N, 0, 0);

    for(vector<char> row : board) {
        for(char col : row) {
            cout << col;
        }
        cout << '\n';
    }
}