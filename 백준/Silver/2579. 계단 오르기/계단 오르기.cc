#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int dp[n], arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = arr[2] + (arr[1] > arr[0] ? arr[1] : arr[0]);

    for (int i=3; i<n; i++) {
        dp[i] = arr[i] + (dp[i-2] > dp[i-3]+arr[i-1] ? dp[i-2] : dp[i-3]+arr[i-1]);
    }
    cout << dp[n-1] << '\n';
}