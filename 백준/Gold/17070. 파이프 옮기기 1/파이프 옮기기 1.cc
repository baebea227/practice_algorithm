#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 17;

int board[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE][3];

void solve() {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }
    
    dp[0][1][0] = 1;

    for(int y=0; y<n; y++) {
        for(int x=0; x<n; x++) {
            if(board[y][x+1] == 0) dp[y][x+1][0] += dp[y][x][0] + dp[y][x][2];
            if(board[y+1][x] == 0) dp[y+1][x][1] += dp[y][x][1] + dp[y][x][2];
            if(board[y][x+1] + board[y+1][x] + board[y+1][x+1] == 0) dp[y+1][x+1][2] += dp[y][x][0] + dp[y][x][1] + dp[y][x][2];
        }
    }

    cout << dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}