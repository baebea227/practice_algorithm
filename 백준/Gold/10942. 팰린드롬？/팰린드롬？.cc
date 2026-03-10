#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int m;
    cin >> m;

    vector<vector<int>> dp(n,vector<int>(n, 0));
    for(int i=0; i<n; i++) dp[i][i] = 1;

    for(int dist=1; dist<n; dist++) {
        for(int i=0; i + dist<n; i++) {
            int j = i + dist;

            if(arr[i] == arr[j]) {
                if(dist == 1) dp[i][j] = 1;
                else dp[i][j] = dp[i+1][j-1];
            }
        }
    }

    while(m--) {
        int s, e;
        cin >> s >> e;
        s--; e--;

        if(dp[s][e]) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
}