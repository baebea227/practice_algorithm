#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> board(n);
    for(int i=0; i<n; i++) {
        cin >> board[i];
    }

    vector<int> ascDp(n, 1);
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(board[i] > board[j]) {
                ascDp[i] = max(ascDp[i], ascDp[j] + 1);
            }
        }
    }

    vector<int> descDp(n, 1);
    for(int i=n-1; i>=0; i--) {
        for(int j=n-1; j>i; j--) {
            if(board[i] > board[j]) {
                descDp[i] = max(descDp[i], descDp[j] + 1);
            }
        }
    }

    int result = 1;
    for(int i=0; i<n; i++) {
        result = max(result, ascDp[i] + descDp[i] - 1);
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}