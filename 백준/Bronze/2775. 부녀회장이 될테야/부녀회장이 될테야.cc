#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int apart[15][14] = {0};
    for (int j=0; j<14; j++) {
        apart[0][j] = j+1;
    }
    for (int i=1; i<15; i++) {
        for (int j=0; j<14; j++) {
            for (int k=0; k<=j; k++) {
                apart[i][j] += apart[i-1][k];
            }
        }
    }

    int nt;
    cin >> nt;
    while(nt--) {
        int k, n;
        cin >> k >> n;
        cout << apart[k][n-1] << '\n';
    }
}