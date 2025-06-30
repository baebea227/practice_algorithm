#include <iostream>
using namespace std;

int num = 0;

void zSearch(int n, int r, int c, int x, int y) {
    if(n == 1) {
        cout << num << '\n';
        return;
    }
    else {
        n = n/2;
        if(c < x+n && r < y+n) {
            zSearch(n, r, c, x, y);
        }
        else if(r < y+n) {
            num += n*n;
            zSearch(n, r, c, x+n, y);
        }
        else if(c < x+n) {
            num += n*n*2;
            zSearch(n, r, c, x, y+n);
        }
        else {
            num += n*n*3;
            zSearch(n, r, c, x+n, y+n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, r, c;
    cin >> n >> r >> c;
    
    int powN=1;
    for (int i=0; i<n; i++) powN *= 2;
    zSearch(powN, r, c, 0, 0);
}