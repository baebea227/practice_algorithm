#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int fiveCnt = n/5;
    while((n-fiveCnt*5)%3 != 0) {
        fiveCnt--;
        if (fiveCnt==-1) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << fiveCnt+(n-fiveCnt*5)/3 << '\n';
}