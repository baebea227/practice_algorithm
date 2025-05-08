#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int cnt=1;
    if (n!=1) {
        n = (n-2)/6 + 1;
        int i=1;
        while (n > 0) {
            n-=i++;
            cnt++;
        }
    }
    cout << cnt << '\n';
}