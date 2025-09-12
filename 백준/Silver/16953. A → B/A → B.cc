#include <iostream>
using namespace std;

int solve() {
    int A, B;
    cin >> A >> B;
    
    int cnt = 1;
    while(B > A) {
        if((B & 1) == 0) B >>= 1;
        else if(B % 10 == 1) B /= 10;
        else break;

        cnt++;

        if(A == B) return cnt;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << solve() << '\n';

    return 0;
}