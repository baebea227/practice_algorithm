#include <iostream>
using namespace std;

int A, C;

long long solve(int n) {
    if(n == 0) return 1;

    long long val = solve(n/2) % C;
    val = val * val % C;
    if(n % 2 == 0) {
        return val;
    }
    else {
        return (val * (A % C)) % C;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int B;
    cin >> A >> B >> C;

    cout << solve(B) << '\n';
}