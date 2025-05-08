#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, n;
    cin >> m >> n;
    
    vector<bool> sosu(n+1, true);
    sosu[1]=false;

    for (int i=2; i*i<=n; i++) {
        if (sosu[i]) {
            for (int j=i*i; j<=n; j+=i) {
                sosu[j] = false;
            }
        }
    }

    for (int i=m; i<=n; i++) {
        if (sosu[i]) cout << i << '\n';
    }
}