#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    int n[t];
    for (int i=0; i<t; i++) {
        cin >> n[i];
    }

    int maxN = *max_element(n, n+t);
    int dp[maxN+1];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int j=4; j<=maxN; j++) {
        dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
    }

    for (int i=0; i<t; i++) {
        cout << dp[n[i]] << '\n';
    }
}