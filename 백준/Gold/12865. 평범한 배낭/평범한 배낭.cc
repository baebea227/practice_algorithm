#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> w(n+1), v(n+1);
    for(int i=1; i<n+1; i++) {
        cin >> w[i] >> v[i];
    }

    vector<int> dp(k+1, 0);
    for(int i=1; i<n+1; i++) {
        for (int j=k; j>=w[i]; j--) {
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }

    cout << dp[k] << '\n';
}