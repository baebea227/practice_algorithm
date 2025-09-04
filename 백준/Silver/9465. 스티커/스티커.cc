#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        vector<vector<int>> dp(3, vector<int>(n, 0));
        for (int i=0; i<2; i++) {
            for (int j=0; j<n; j++) {
                cin >> dp[i][j];
            }
        }

        for(int i=1; i<n; i++) {
            dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + dp[0][i];
            dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + dp[1][i];
            dp[2][i] = max(max(dp[0][i-1], dp[1][i-1]), dp[2][i-1]);
        }

        cout << max(max(dp[0][n-1], dp[1][n-1]), dp[2][n-1]) << '\n';
    }
}