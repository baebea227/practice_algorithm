#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
vector<int> board;

bool check(int col, int row) {
    for(int i=0; i<row; i++) {
        if(board[i] == col || abs(board[i] - col) == row - i)
            return false;
    }   
    return true;
}

void solve(int row) {
    if(row == n) {
        cnt++;
        return;
    }

    for(int col=0; col<n; col++) {
        if(check(col, row)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    board.resize(n);
    solve(0);

    cout << cnt << '\n';
}