// [1 1]^n = [F(n+1) F(n)  ]
// [1 0]   = [F(n)   F(n-1)]

#include <iostream>
using namespace std;

struct Mat {
    long long m[2][2];
};

const long long maxNum = 1000000007;
const Mat base = {{{1, 1}, {1, 0}}};

Mat MatMul(const Mat& a, const Mat& b) {
    Mat c = {{{0, 0}, {0, 0}}};

    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<2; k++) {
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % maxNum;
            }
        }
    }

    return c;
}

Mat Fib(long long n) {
    if(n == 1) return base;

    Mat half = Fib(n/2);
    half = MatMul(half, half);

    if(n % 2) return MatMul(half, base);
    else return half;
}

void solve() {
    long long n;
    cin >> n;
    
    cout << Fib(n).m[0][1] % maxNum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}