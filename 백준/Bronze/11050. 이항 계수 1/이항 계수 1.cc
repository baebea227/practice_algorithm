#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    int N=1, K=1, NK=1;
    for (int i=2; i<=n; i++) {
        N *= i;
    }
    for (int i=2; i<=k; i++) {
        K *= i;
    }
    for (int i=2; i<=n-k; i++) {
        NK *= i;
    }
    cout << N/(K*NK) << '\n';
}