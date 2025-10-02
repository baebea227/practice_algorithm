#include <iostream>
using namespace std;


void solve() {
    int n;
    cin >> n;
    
    int maxDp[3] = {};
    int minDp[3] = {};
    
    for(int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        int nextMaxDp[3];
        int nextMinDp[3];
        
        nextMaxDp[0] = a + max(maxDp[0], maxDp[1]);
        nextMaxDp[1] = b + max(maxDp[0], max(maxDp[1], maxDp[2]));
        nextMaxDp[2] = c + max(maxDp[1], maxDp[2]);

        nextMinDp[0] = a + min(minDp[0], minDp[1]);
        nextMinDp[1] = b + min(minDp[0], min(minDp[1], minDp[2]));
        nextMinDp[2] = c + min(minDp[1], minDp[2]);

        for(int i=0; i<3; i++) {
            maxDp[i] = nextMaxDp[i];
            minDp[i] = nextMinDp[i];
        }
    }

    cout << max(maxDp[0], max(maxDp[1], maxDp[2])) << " " << min(minDp[0], min(minDp[1], minDp[2])) <<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}