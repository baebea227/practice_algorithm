#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int nt;
    cin >> nt;
    
    for (int t=0; t<nt; t++) {
        int n;
        cin >> n;
        int a=0, b=1, tmp;
        for (int i=0; i<n-1; i++) {
            tmp=a+b;
            a=b;
            b=tmp;
        }
        if (n==0) {
            cout << 1 << " " << 0 << '\n';
        }
        else cout << a << " " << b << '\n';
    }
}