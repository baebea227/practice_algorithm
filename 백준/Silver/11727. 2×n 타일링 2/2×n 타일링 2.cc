#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int arr[1001];

    arr[1] = 1;
    arr[2] = 3;

    for (int i=3; i<=n; i++) {
        arr[i] = (arr[i-1] + arr[i-2]*2) % 10007;
    }
    cout << arr[n] << '\n';
}