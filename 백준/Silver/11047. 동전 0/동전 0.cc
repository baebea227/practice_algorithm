#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    int arr[n];
    for (int i=n-1; i>=0; i--) {
        cin >> arr[i];
    }
    
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (k / arr[i] > 0) {
            cnt += k / arr[i];
            k %= arr[i];
        }
    }
    cout << cnt << '\n';
}