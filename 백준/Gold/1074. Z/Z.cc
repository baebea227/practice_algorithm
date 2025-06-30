#include <iostream>
using namespace std;

int zSearch(int n, int r, int c) {
    if(n == 0) return 0;
    n = n/2;
    if(r < n && c < n) return zSearch(n, r, c);
    else if(r < n) return zSearch(n, r, c-n) + n*n;
    else if(c < n) return zSearch(n, r-n, c) + n*n * 2;
    else return zSearch(n, r-n, c-n) + n*n * 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, r, c;
    cin >> n >> r >> c;
    
    int powN=1;
    for (int i=0; i<n; i++) powN *= 2;
    cout << zSearch(powN, r, c) << '\n';
}