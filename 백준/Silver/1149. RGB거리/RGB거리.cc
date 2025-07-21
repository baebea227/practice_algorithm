#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<vector<int>> v(n+1, vector<int>(3));
    vector<vector<int>> dp(n+1, vector<int>(3));
    for (int i=1; i<=n; i++) {
        for(int j=0; j<3; j++) {
            cin >> v[i][j];
        }
    }

    for (int i=0; i<3; i++) {
        dp[1][i] = v[1][i];
    }

    for (int i=2; i<=n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + v[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + v[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + v[i][2];
    }
    
    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
}