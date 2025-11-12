// [1 1]^n = [F(n+1) F(n)  ]
// [1 0]   = [F(n)   F(n-1)]

#include <iostream>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

struct Mat {
    ll m[2][2];
};

const Mat base = {{{1, 1}, {1, 0}}};

Mat MatMul(const Mat& a, const Mat& b) {
    Mat c = {{{0, 0}, {0, 0}}};

    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<2; k++) {
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
            }
        }
    }

    return c;
}

Mat Fib(ll n) {
    if(n == 1) return base;

    Mat half = Fib(n/2);
    Mat res = MatMul(half, half);

    if(n % 2) res = MatMul(res, base);
    
    return res;
}

void solve() {
    ll n;
    cin >> n;
    
    cout << Fib(n).m[0][1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}