#include <iostream>
using namespace std;

int A, C;

long long solve(int n) {
    if(n == 0) return 1;

    long long result;
    if(n % 2 == 0) {
        result = solve(n/2) % C;
        return (result * result) % C;
    }
    else {
        result = solve((n-1)/2) % C;
        return (((result * result) % C) * (A % C)) % C;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int B;
    cin >> A >> B >> C;

    cout << solve(B) << '\n';
}