#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<vector<int>> dp(n+1, vector<int>(3));
    for (int i=1; i<=n; i++) {
        for(int j=0; j<3; j++) {
            cin >> dp[i][j];
        }
    }

    for (int i=2; i<=n; i++) {
        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
    }
    
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';
}