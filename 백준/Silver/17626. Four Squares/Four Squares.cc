#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for(int i=0; i*i<=n; i++) {
        for(int j=0; j*j<=n; j++) {
            for(int k=0; k*k<=n; k++) {
                for(int l=0; l*l<=n; l++) {
                    if(i*i+j*j+k*k+l*l == n) {
                        cout << (i != 0) + (j != 0) + (k != 0) + (l != 0)<< '\n';
                        return 0;
                    }
                }
            }
        }
    }
    
}