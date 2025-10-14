#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> mat(N+1);
    for(int i=0; i<N; i++) {
        cin >> mat[i] >> mat[i+1];
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));

    for(int diag=1; diag<N; diag++) {
        for(int y=0; y<N-diag; y++) {
            int x = y + diag;
            dp[y][x] = INT_MAX;
            
            for(int k=y; k<x; k++) {
                dp[y][x] = min(dp[y][x], dp[y][k] + dp[k+1][x] + mat[y]*mat[k+1]*mat[x+1]);
            }
        }
    }
    
    cout << dp[0][N-1] << '\n';
}