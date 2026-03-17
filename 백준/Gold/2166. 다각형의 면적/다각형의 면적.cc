#include <bits/stdc++.h>
using namespace std;

struct pos {
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pos> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    long long sum = 0;
    for(int i=0; i<n; i++) {
        int j = (i+1) % n;
        sum += arr[i].x * arr[j].y - arr[j].x * arr[i].y; // 신발끈 공식
    }
    double ans = abs(sum) / 2.0;

    cout << fixed;
    cout.precision(1);
    cout << ans << '\n';
}