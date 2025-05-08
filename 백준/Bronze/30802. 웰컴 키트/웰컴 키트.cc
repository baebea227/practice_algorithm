#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int s, m, l, xl, xxl, xxxl;
    cin >> s >> m >> l >> xl >> xxl >> xxxl;
    int t, p;
    cin >> t >> p;

    cout << (s+t-1)/t + (m+t-1)/t + (l+t-1)/t + (xl+t-1)/t + (xxl+t-1)/t + (xxxl+t-1)/t   << '\n' << n/p << " " << n%p << '\n'; 
}