#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    int aLength = a.length();
    int bLength = b.length();

    vector<vector<int>> dp(aLength+1, vector<int>(bLength+1, 0));
    for(int i=0; i<aLength; i++) {
        for(int j=0; j<bLength; j++) {
            if(a[i] == b[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    
    cout << dp[aLength][bLength] << '\n';

    string answer = "";
    int i = aLength, j = bLength;

    while(i > 0 && j > 0) {
        if(dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == dp[i][j-1]) j--;
        else {
            answer.push_back(a[i-1]);
            i--; j--;
        }
    }

    reverse(answer.begin(), answer.end());

    cout << answer << '\n';
}