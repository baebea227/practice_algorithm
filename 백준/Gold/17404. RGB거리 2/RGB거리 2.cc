#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(3));
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> arr[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(3));
    int ans = INF;

    for(int k=0; k<3; k++) { // k = first RGB color
        for(int i=0; i<3; i++) {
            if(i == k) dp[0][i] = arr[0][i];
            else dp[0][i] = INF;
        }

        for(int i=1; i<n; i++) {
            dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }

        for(int i=0; i<3; i++) {
            if(i == k) continue;
            ans = min(ans, dp[n-1][i]);
        }
    }

    cout << ans << "\n";
}