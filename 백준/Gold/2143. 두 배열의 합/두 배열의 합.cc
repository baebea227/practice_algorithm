#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i]; 
    
    int m;
    cin >> m;
    vector<int> B(m);
    for(int i=0; i<m; i++) cin >> B[i];

    vector<int> sumA;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += A[j];
            sumA.push_back(sum);
        }
    }

    vector<int> sumB;
    for(int i=0; i<m; i++) {
        int sum = 0;
        for(int j=i; j<m; j++) {
            sum += B[j];
            sumB.push_back(sum);
        }
    }

    sort(sumB.begin(), sumB.end());

    long long ans = 0;
    for(int a : sumA) {
        int target = T - a;

        auto upper = upper_bound(sumB.begin(), sumB.end(), target);
        auto lower = lower_bound(sumB.begin(), sumB.end(), target);

        ans += upper - lower;
    }

    cout << ans << '\n';
}