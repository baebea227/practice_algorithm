#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

long long inv(int x, int n = mod-2) {
    if(n == 0) return 1;

    long long half = inv(x, n/2);
    half = half * half % mod;

    if(n % 2 == 0)
        return half;
    else
        return x * half % mod;
}

void solve() {
    int M;
    cin >> M;

    int result = 0;

    for(int i=0; i<M; i++) {
        int n, s;
        cin >> n >> s;

        result = (result + (s * inv(n))) % mod;
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}