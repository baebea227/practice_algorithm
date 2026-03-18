#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> w(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> w[i][j];
        }
    }
    
    vector<vector<int>> dp(1 << n, vector<int>(n, INF)); // dp[mask(2 ^ N)][curr(N)]
    dp[1][0] = 0;
    
    for(int mask=1; mask < (1 << n); mask++) {
        for(int curr=0; curr<n; curr++) {
            if(!(mask & (1 << curr)) || dp[mask][curr] == INF) continue;

            for(int next=0; next<n; next++) {
                if(mask & (1 << next) || w[curr][next] == 0) continue;

                int nextMask = mask | (1 << next);
                dp[nextMask][next] = min(dp[nextMask][next], dp[mask][curr] + w[curr][next]);
            }
        }
    }

    int minSum = INF;
    int fullMask = (1 << n) - 1;

    for(int i=0; i<n; i++) {
        if(w[i][0] != 0 && dp[fullMask][i] != INF) {
            minSum = min(minSum, dp[fullMask][i] + w[i][0]);
        }
    }

    cout << minSum << '\n';
}